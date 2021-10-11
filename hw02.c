#include    <stdio.h>
#include    <stdlib.h>
#define     Maxfloor 3
#define     Maxrow 105
#define     Maxcol 105
#define     Maxstack 20000

//romeo&juliet
struct      stack{
    int     f;
    int     c;
    int     r;
    char    move;  //right or left or up or down
    char    go_before;
};

//pop
void    pop(struct stack *rp,int top){
    rp[top].go_before='X';
}

//push
void    push(struct stack *rp,char move,int top){
    int     top2;
    top2=(top+1);
    switch(move){
        case 'r':
            rp[top2].f=rp[top].f;
            rp[top2].c=(rp[top].c)+1;
            rp[top2].r=rp[top].r;
            rp[top2].move='r';
            rp[top2].go_before='Y';
            break;
        case 'l':
            rp[top2].f=rp[top].f;
            rp[top2].c=(rp[top].c)-1;
            rp[top2].r=rp[top].r;
            rp[top2].move='l';
            rp[top2].go_before='Y';
            break;
        case 'u':
            rp[top2].f=rp[top].f;
            rp[top2].c=rp[top].c;
            rp[top2].r=(rp[top].r)-1;
            rp[top2].move='u';
            rp[top2].go_before='Y';
            break;
        case 'd':
            rp[top2].f=rp[top].f;
            rp[top2].c=rp[top].c;
            rp[top2].r=(rp[top].r)+1;
            rp[top2].move='d';
            rp[top2].go_before='Y';
            break;
    }
}
//print
void    print(struct stack *romeo,struct stack *juliet,int top_r,int top_j,int flag,int *round){
    int     one=1;
    if(flag==1){  //only romeo move and they encounter
        printf("==Round: %d==\nRomeo: (%d,%d,%d)\nJuliet: (%d,%d,%d)\n",*round,romeo[top_r].f,romeo[top_r].c,romeo[top_r].r,juliet[top_j].f,juliet[top_j].c,juliet[top_j].r);
        printf("They encounter each other in (%d,%d,%d)",romeo[top_r].f,romeo[top_r].c,romeo[top_r].r);
        round=&one;
        exit(0);
    }
    else{
        if((romeo[top_r].f==juliet[top_j].f)&&(romeo[top_r].c==juliet[top_j].c)&&(romeo[top_r].r==juliet[top_j].r)){
            printf("==Round: %d==\nRomeo: (%d,%d,%d)\nJuliet: (%d,%d,%d)\n",*round,romeo[top_r].f,romeo[top_r].c,romeo[top_r].r,juliet[top_j].f,juliet[top_j].c,juliet[top_j].r);
            printf("They encounter each other in (%d,%d,%d)",romeo[top_r].f,romeo[top_r].c,romeo[top_r].r);
            round=&one;
            exit(0);
        }
        else{
            if((romeo[top_r].f==1&&romeo[top_r].c==99&&romeo[top_r].r==99)||(juliet[top_j].f==0&&juliet[top_j].c==1&&juliet[top_j].r==1)){  //they do not encounter but one of them goes out
                printf("==Round: %d==\nRomeo: (%d,%d,%d)\nJuliet: (%d,%d,%d)\n",*round,romeo[top_r].f,romeo[top_r].c,romeo[top_r].r,juliet[top_j].f,juliet[top_j].c,juliet[top_j].r);
		printf("They do not encounter each other in this maze.");
                round=&one;
                exit(0);
            }
            else{  //they de not encounter and no one goes out
                printf("==Round: %d==\nRomeo: (%d,%d,%d)\nJuliet: (%d,%d,%d)\n",*round,romeo[top_r].f,romeo[top_r].c,romeo[top_r].r,juliet[top_j].f,juliet[top_j].c,juliet[top_j].r);
                *round=*round+one;
            }
        }
    }
}

int     main(){
    //input
    int     floor=0,col=0,row=-1;
    char    c;
    //use tow maze to store the char
    char    maze[Maxfloor][Maxcol][Maxrow];
    char    maze2[Maxfloor][Maxcol][Maxrow];
    scanf("%d",&floor);
    if(floor==1){
        for(int i=0;i<10302;i++){
            c=getchar();
            if(c!='X'&&c!='.'&&c!='o'){
                col=0;
            }
            else{
                if(col==0){
                    row++;
                }
                maze[0][col][row]=c;
                maze2[0][col][row]=c;
                col++;
            }
        }
    }
    col=0;
    row=-1;
    scanf("%d",&floor);
    if(floor==2){
        for(int i=0;i<10302;i++){
            c=getchar();
            if(c!='X'&&c!='.'&&c!='o'){
                col=0;
            }
            else{

                if(col==0){
                    row++;
                }
                maze[1][col][row]=c;
                maze2[1][col][row]=c;
                col++;
            }
        }
    }
    //go maze
    int     top_r=0,top_j=0,flag=0,stair_j=0,stair_r=0,round=1;
    struct stack romeo[Maxstack]={0};
    romeo[top_r].f=0;
    romeo[top_r].c=1;
    romeo[top_r].r=1;
    romeo[top_r].move='N';
    romeo[top_r].go_before='Y';
    struct stack juliet[Maxstack]={0};
    juliet[top_j].f=1;
    juliet[top_j].c=99;
    juliet[top_j].r=99;
    juliet[top_j].move='N';
    juliet[top_j].go_before='Y';
    char    move;


    for(int i=0;;i++){
        //romeo
        for(int j=0;j<1;j++){
            //right:c++ ; left:c-- ; down:r++ ; up:r--
            //if meet 'o' second time
            if(maze[romeo[top_r].f][(romeo[top_r].c+1)][romeo[top_r].r]=='o'&&stair_r==2){
                maze[romeo[top_r].f][(romeo[top_r].c+1)][romeo[top_r].r]='X';
            }
            else if(maze[romeo[top_r].f][(romeo[top_r].c-1)][romeo[top_r].r]=='o'&&stair_r==2){
                maze[romeo[top_r].f][(romeo[top_r].c-1)][romeo[top_r].r]='X';
            }
            else if(maze[romeo[top_r].f][romeo[top_r].c][(romeo[top_r].r+1)]=='o'&&stair_r==2){
                maze[romeo[top_r].f][romeo[top_r].c][(romeo[top_r].r+1)]='X';
            }
            else if(maze[romeo[top_r].f][romeo[top_r].c][(romeo[top_r].r-1)]=='o'&&stair_r==2){
                maze[romeo[top_r].f][romeo[top_r].c][(romeo[top_r].r-1)]='X';
            }
            //right
            if(maze[romeo[top_r].f][(romeo[top_r].c+1)][romeo[top_r].r]!='X'&&romeo[top_r].move!='l'){
                //if meet 'o' the first time
                if(maze[romeo[top_r].f][(romeo[top_r].c+1)][romeo[top_r].r]=='o'&&stair_r==0){
                    romeo[top_r].f=1;
                    stair_r=1;
                }
                //keep going
                move='r';
                push(romeo,move,top_r);
                top_r++;
                //if romeo go up stair, moving need to initialization
                if(stair_r==1){
                    romeo[top_r].move='N';
                    stair_r=2;
                }
                //if romeo goes one step, he meets Juliet
                if((romeo[top_r].f==juliet[top_j].f)&&(romeo[top_r].c==juliet[top_j].c)&&(romeo[top_r].r==juliet[top_j].r)){
                    flag=1;
                    print(romeo,juliet,top_r,top_j,flag,&round);
                }
            }
            else{
                //down
                if(maze[romeo[top_r].f][romeo[top_r].c][(romeo[top_r].r+1)]!='X'&&romeo[top_r].move!='u'){
                    //if meet 'o' the first time
                    if(maze[romeo[top_r].f][romeo[top_r].c][(romeo[top_r].r+1)]=='o'&&stair_r==0){
                        romeo[top_r].f=1;
                        stair_r=1;
                    }
                    //keep going
                    move='d';
                    push(romeo,move,top_r);
                    top_r++;
                    //if romeo go up stair, moving need to initialization
                    if(stair_r==1){
                        romeo[top_r].move='N';
                        stair_r=2;
                    }
                    //if romeo goes one step, he meets Juliet
                    if((romeo[top_r].f==juliet[top_j].f)&&(romeo[top_r].c==juliet[top_j].c)&&(romeo[top_r].r==juliet[top_j].r)){
                        flag=1;
                        print(romeo,juliet,top_r,top_j,flag,&round);
                    }
                }
                else{
                    //up
                    if(maze[romeo[top_r].f][romeo[top_r].c][(romeo[top_r].r-1)]!='X'&&romeo[top_r].move!='d'){
                        //if meet 'o' the first time
                        if(maze[romeo[top_r].f][romeo[top_r].c][(romeo[top_r].r-1)]=='o'&&stair_r==0){
                            romeo[top_r].f=1;
                            stair_r=1;
                        }
                        //keep going
                        move='u';
                        push(romeo,move,top_r);
                        top_r++;
                        //if romeo go up stair, moving need to initialization
                        if(stair_r==1){
                            romeo[top_r].move='N';
                            stair_r=2;
                        }
                        //if romeo goes one step, he meets Juliet
                        if((romeo[top_r].f==juliet[top_j].f)&&(romeo[top_r].c==juliet[top_j].c)&&(romeo[top_r].r==juliet[top_j].r)){
                            flag=1;
                            print(romeo,juliet,top_r,top_j,flag,&round);
                        }
                    }
                    else{
                        //left
                        if(maze[romeo[top_r].f][(romeo[top_r].c-1)][romeo[top_r].r]!='X'&&romeo[top_r].move!='r'){
                            //if meet 'o' the first time
                            if(maze[romeo[top_r].f][(romeo[top_r].c-1)][romeo[top_r].r]=='o'&&stair_r==0){
                                romeo[top_r].f=1;
                                stair_r=1;
                            }
                            //keep going
                            move='l';
                            push(romeo,move,top_r);
                            top_r++;
                            //if romeo go up stair, moving need to initialization
                            if(stair_r==1){
                                romeo[top_r].move='N';
                                stair_r=2;
                            }
                            //if romeo goes one step, he meets Juliet
                            if((romeo[top_r].f==juliet[top_j].f)&&(romeo[top_r].c==juliet[top_j].c)&&(romeo[top_r].r==juliet[top_j].r)){
                                flag=1;
                                print(romeo,juliet,top_r,top_j,flag,&round);
                            }
                        }
                        else{  //need to go back
                            maze[romeo[top_r].f][romeo[top_r].c][romeo[top_r].r]='X';
                            pop(romeo,top_r);
                            top_r--;
                            if((romeo[top_r].f==juliet[top_j].f)&&(romeo[top_r].c==juliet[top_j].c)&&(romeo[top_r].r==juliet[top_j].r)){
                                flag=1;
                                print(romeo,juliet,top_r,top_j,flag,&round);
                            }
                        }
                    }
                }
            }
        }
        //juliet
        for(int j=0;j<1;j++){
            //if meet 'o' second time
            if(maze2[juliet[top_j].f][(juliet[top_j].c+1)][juliet[top_j].r]=='o'&&stair_j==2){
                maze2[juliet[top_j].f][(juliet[top_j].c+1)][juliet[top_j].r]='X';
            }
            else if(maze2[juliet[top_j].f][(juliet[top_j].c-1)][juliet[top_j].r]=='o'&&stair_j==2){
                maze2[juliet[top_j].f][(juliet[top_j].c-1)][juliet[top_j].r]='X';
            }
            else if(maze2[juliet[top_j].f][juliet[top_j].c][(juliet[top_j].r+1)]=='o'&&stair_j==2){
                maze2[juliet[top_j].f][juliet[top_j].c][(juliet[top_j].r+1)]='X';
            }
            else if(maze2[juliet[top_j].f][juliet[top_j].c][(juliet[top_j].r-1)]=='o'&&stair_j==2){
                maze2[juliet[top_j].f][juliet[top_j].c][(juliet[top_j].r-1)]='X';
            }
            //left
            if(maze2[juliet[top_j].f][(juliet[top_j].c-1)][juliet[top_j].r]!='X'&&juliet[top_j].move!='r'){
                //if meet 'o' the first time
                if(maze2[juliet[top_j].f][(juliet[top_j].c-1)][juliet[top_j].r]=='o'&&stair_j==0){
                    juliet[top_j].f=0;
                    stair_j=1;
                }
                //keep going
                move='l';
                push(juliet,move,top_j);
                top_j++;
                //if Juleit go down stair, moving need to initialization
                if(stair_j==1){
                    juliet[top_j].move='N';
                    stair_j=2;
                }
                print(romeo,juliet,top_r,top_j,flag,&round);
            }
            else{
                //up
                if(maze2[juliet[top_j].f][juliet[top_j].c][(juliet[top_j].r-1)]!='X'&&juliet[top_j].move!='d'){
                    if(maze2[juliet[top_j].f][juliet[top_j].c][(juliet[top_j].r-1)]=='o'&&stair_j==0){
                        juliet[top_j].f=0;
                        stair_j=1;
                    }
                    //keep going
                    move='u';
                    push(juliet,move,top_j);
                    top_j++;
                    //if Juleit go down stair, moving need to initialization
                    if(stair_j==1){
                        juliet[top_j].move='N';
                        stair_j=2;
                    }
                    print(romeo,juliet,top_r,top_j,flag,&round);
                }
                else{
                    //down
                    if(maze2[juliet[top_j].f][juliet[top_j].c][(juliet[top_j].r+1)]!='X'&&juliet[top_j].move!='u'){
                        //if meet 'o' the first time
                        if(maze2[juliet[top_j].f][juliet[top_j].c][(juliet[top_j].r+1)]=='o'&&stair_j==0){
                            juliet[top_j].f=0;
                            stair_j=1;
                        }
                        //keep going
                        move='d';
                        push(juliet,move,top_j);
                        top_j++;
                        //if Juleit go down stair, moving need to initialization
                        if(stair_j==1){
                            juliet[top_j].move='N';
                            stair_j=2;
                        }
                        print(romeo,juliet,top_r,top_j,flag,&round);
                    }
                    else{
                        //right
                        if(maze2[juliet[top_j].f][(juliet[top_j].c+1)][juliet[top_j].r]!='X'&&juliet[top_j].move!='l'){
                            //if meet 'o' the first time
                            if(maze2[juliet[top_j].f][(juliet[top_j].c+1)][juliet[top_j].r]=='o'&&stair_j==0){
                                juliet[top_j].f=0;
                                stair_j=1;
                            }
                            //keep going
                            move='r';
                            push(juliet,move,top_j);
                            top_j++;
                            //if Juleit go down stair, moving need to initialization
                            if(stair_j==1){
                                juliet[top_j].move='N';
                                stair_j=2;
                            }
                            print(romeo,juliet,top_r,top_j,flag,&round);
                        }
                        else{ //need to go back
                            maze2[juliet[top_j].f][juliet[top_j].c][juliet[top_j].r]='X';
                            pop(juliet,top_j);
                            top_j--;
                            print(romeo,juliet,top_r,top_j,flag,&round);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
                                             
