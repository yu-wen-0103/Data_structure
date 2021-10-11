#include    <stdio.h>

void    Print(char  *immovable){
    printf("YES\n");
    for(int i=0;i<9;i++){
        if(immovable[i]=='0'){
            printf("2");
        }
        else{
            printf("1");
        }
        if(i==2||i==5||i==8){  //each row has 3 elements
            printf("\n");
        }
    }
}

int     main(){
    int     num=0,immovable_full=0,movable_full=0,cnt=0,cnt2=0;
    char    c;
    char    immovable[10],movable[10];
    scanf("%d",&num);  //input the number of test cases
    for(int i=0;i<num;i++){
        cnt=0;
        cnt2=0;
        for(int j=0;j<12;j++){  //put element into matrix(immovable)
            c=getchar();
            if(c=='\n'){
                continue;
            }
            else{
                immovable[cnt++]=c;
                if(c=='1'){  //calculate how much elements are be occupied
                    immovable_full++;
                }
            }
        }
	for(int k=0;k<12;k++){  //put element into matrix(movable)
            c=getchar();
            if(c=='\n'){
                continue;
            }
            else{
                movable[cnt2++]=c;
                if(c=='2'){  //calculate how much elements are be occupied
                    movable_full++;
                }
            }
        }
        //judge if match or not
        if((immovable_full+movable_full)==9){  //maybe can match
            //case 1:movable or immovable matrix only has one or zero '2'
            if(movable_full==1||movable_full==8||movable_full==9){
                Print(immovable);
            }
            //case 2:movable matrix has two '2'
            else if(movable_full==2){
                if((immovable[0]=='0'&&immovable[1]=='0')||(immovable[0]=='0'&&immovable[3]=='0')||(immovable[1]=='0'&&immovable[2]=='0')||(immovable[1]=='0'&&immovable[4]=='0')||(immovable[2]=='0'&&immovable[5]=='0')||(immovable[3]=='0'&&immovable[4]=='0')||(immovable[4]=='0'&&immovable[5]=='0')||(immovable[3]=='0'&&immovable[6]=='0')||(immovable[4]=='0'&&immovable[7]=='0')||(immovable[5]=='0'&&immovable[8]=='0')||(immovable[6]=='0'&&immovable[7]=='0')||(immovable[7]=='0'&&immovable[8]=='0')){
                    Print(immovable);
                }
                else{
                    printf("NO\n");
                }
            }
	    else if(movable_full==4){
                //case 5:movable matrix has four '2'(��)
                if((movable[0]=='2'&&movable[1]=='2'&&movable[3]=='2'&&movable[4]=='2')||(movable[1]=='2'&&movable[2]=='2'&&movable[4]=='2'&&movable[5]=='2')||(movable[3]=='2'&&movable[4]=='2'&&movable[6]=='2'&&movable[7]=='2')||(movable[4]=='2'&&movable[5]=='2'&&movable[7]=='2'&&movable[8]=='2')){
                    Print(immovable);
                }
                //case 6:movable matrix has four '2'(three horizontal & more one at left)
                else if((movable[0]=='2'&&movable[3]=='2'&&movable[4]=='2'&&movable[5]=='2')||(movable[3]=='2'&&movable[6]=='2'&&movable[7]=='2'&&movable[8]=='2')||(movable[1]=='2'&&movable[4]=='2'&&movable[7]=='2'&&movable[6]=='2')||(movable[7]=='2'&&movable[8]=='2'&&movable[5]=='2'&&movable[2]=='2')||(movable[0]=='2'&&movable[1]=='2'&&movable[2]=='2'&&movable[5]=='2')||(movable[3]=='2'&&movable[4]=='2'&&movable[5]=='2'&&movable[8]=='2')||(movable[0]=='2'&&movable[1]=='2'&&movable[3]=='2'&&movable[6]=='2')||(movable[2]=='2'&&movable[1]=='2'&&movable[4]=='2'&&movable[7]=='2')){
                    Print(immovable);
                }
                //case 7:movable matrix has four '2'(three horizontal & more one at right)
                else if((movable[2]=='2'&&movable[3]=='2'&&movable[4]=='2'&&movable[5]=='2')||(movable[5]=='2'&&movable[6]=='2'&&movable[7]=='2'&&movable[8]=='2')||(movable[1]=='2'&&movable[4]=='2'&&movable[7]=='2'&&movable[0]=='2')||(movable[1]=='2'&&movable[8]=='2'&&movable[5]=='2'&&movable[2]=='2')||(movable[0]=='2'&&movable[1]=='2'&&movable[2]=='2'&&movable[3]=='2')||(movable[3]=='2'&&movable[4]=='2'&&movable[5]=='2'&&movable[6]=='2')||(movable[0]=='2'&&movable[3]=='2'&&movable[6]=='2'&&movable[7]=='2')||(movable[8]=='2'&&movable[1]=='2'&&movable[4]=='2'&&movable[7]=='2')){
                    Print(immovable);
                }
                //case 8:movable matrix has four '2'(three horizontal & more one at middle)
                else if((movable[1]=='2'&&movable[3]=='2'&&movable[4]=='2'&&movable[5]=='2')||(movable[4]=='2'&&movable[6]=='2'&&movable[7]=='2'&&movable[8]=='2')||(movable[1]=='2'&&movable[4]=='2'&&movable[7]=='2'&&movable[3]=='2')||(movable[4]=='2'&&movable[8]=='2'&&movable[5]=='2'&&movable[2]=='2')||(movable[0]=='2'&&movable[1]=='2'&&movable[2]=='2'&&movable[4]=='2')||(movable[3]=='2'&&movable[4]=='2'&&movable[5]=='2'&&movable[7]=='2')||(movable[0]=='2'&&movable[3]=='2'&&movable[6]=='2'&&movable[4]=='2')||(movable[5]=='2'&&movable[1]=='2'&&movable[4]=='2'&&movable[7]=='2')){
                    Print(immovable);
                }
		else{
                    printf("NO\n");
                }
            }
            else if(movable_full==5){
                //case 9:movable matrix has five '2'(three horizontal & two at left and middle)
                if((movable[2]=='0'&&movable[6]=='0'&&movable[7]=='0'&&movable[8]=='0')||(movable[0]=='0'&&movable[1]=='0'&&movable[2]=='0'&&movable[5]=='0')||(movable[0]=='0'&&movable[2]=='0'&&movable[5]=='0'&&movable[8]=='0')||(movable[0]=='0'&&movable[1]=='0'&&movable[3]=='0'&&movable[6]=='0')||(movable[3]=='0'&&movable[6]=='0'&&movable[7]=='0'&&movable[8]=='0')||(movable[0]=='0'&&movable[1]=='0'&&movable[2]=='0'&&movable[6]=='0')||(movable[2]=='0'&&movable[5]=='0'&&movable[7]=='0'&&movable[8]=='0')||(movable[0]=='0'&&movable[3]=='0'&&movable[6]=='0'&&movable[8]=='0')){
                    if((immovable[2]=='1'&&immovable[6]=='1'&&immovable[7]=='1'&&immovable[8]=='1')||(immovable[0]=='1'&&immovable[1]=='1'&&immovable[2]=='1'&&immovable[5]=='1')||(immovable[0]=='1'&&immovable[2]=='1'&&immovable[5]=='1'&&immovable[8]=='1')||(immovable[0]=='1'&&immovable[1]=='1'&&immovable[3]=='1'&&immovable[6]=='1')||(immovable[3]=='1'&&immovable[6]=='1'&&immovable[7]=='1'&&immovable[8]=='1')||(immovable[0]=='1'&&immovable[1]=='1'&&immovable[2]=='1'&&immovable[6]=='1')||(immovable[2]=='1'&&immovable[5]=='1'&&immovable[7]=='1'&&immovable[8]=='1')||(immovable[0]=='1'&&immovable[3]=='1'&&immovable[6]=='1'&&immovable[8]=='1')){
                        Print(immovable);
                    }
                    else{
                        printf("NO\n");
                    }
                }
                //case 10:movable matrix has five '2'(three horizontal & two at right and middle)
                else if((movable[0]=='0'&&movable[6]=='0'&&movable[7]=='0'&&movable[8]=='0')||(movable[0]=='0'&&movable[1]=='0'&&movable[2]=='0'&&movable[3]=='0')||(movable[0]=='0'&&movable[3]=='0'&&movable[6]=='0'&&movable[7]=='0')||(movable[6]=='0'&&movable[2]=='0'&&movable[5]=='0'&&movable[8]=='0')||(movable[5]=='0'&&movable[6]=='0'&&movable[7]=='0'&&movable[8]=='0')||(movable[0]=='0'&&movable[1]=='0'&&movable[2]=='0'&&movable[8]=='0')||(movable[2]=='0'&&movable[5]=='0'&&movable[1]=='0'&&movable[8]=='0')||(movable[0]=='0'&&movable[3]=='0'&&movable[6]=='0'&&movable[2]=='0')){
			if((immovable[0]=='1'&&immovable[6]=='1'&&immovable[7]=='1'&&immovable[8]=='1')||(immovable[0]=='1'&&immovable[1]=='1'&&immovable[2]=='1'&&immovable[3]=='1')||(immovable[0]=='1'&&immovable[3]=='1'&&immovable[6]=='1'&&immovable[7]=='1')||(immovable[2]=='1'&&immovable[5]=='1'&&immovable[6]=='1'&&immovable[8]=='1')||(immovable[5]=='1'&&immovable[6]=='1'&&immovable[7]=='1'&&immovable[8]=='1')||(immovable[0]=='1'&&immovable[1]=='1'&&immovable[2]=='1'&&immovable[8]=='1')||(immovable[2]=='1'&&immovable[5]=='1'&&immovable[1]=='1'&&immovable[8]=='1')||(immovable[0]=='1'&&immovable[3]=='1'&&immovable[6]=='1'&&immovable[2]=='1')){
                        Print(immovable);
                    }
                    else{
                        printf("NO\n");
                    }
                }
                //case 11:movable matrix has five '2'(three horizontal & two both at middle)
                else if((movable[0]=='0'&&movable[2]=='0'&&movable[3]=='0'&&movable[5]=='0')||(movable[0]=='0'&&movable[1]=='0'&&movable[6]=='0'&&movable[7]=='0')||(movable[3]=='0'&&movable[5]=='0'&&movable[6]=='0'&&movable[8]=='0')||(movable[1]=='0'&&movable[2]=='0'&&movable[7]=='0'&&movable[8]=='0')){
                    if((immovable[0]=='1'&&immovable[2]=='1'&&immovable[3]=='1'&&immovable[5]=='1')||(immovable[0]=='1'&&immovable[1]=='1'&&immovable[6]=='1'&&immovable[7]=='1')||(immovable[3]=='1'&&immovable[5]=='1'&&immovable[6]=='1'&&immovable[8]=='1')||(immovable[1]=='1'&&immovable[2]=='1'&&immovable[7]=='1'&&immovable[8]=='1')){
                        Print(immovable);
                    }
                    else{
                        printf("NO\n");
                    }
                }
                //case 12:movable matrix has five '2'(three horizontal & two at left and right)
                else if((movable[1]=='0'&&movable[6]=='0'&&movable[7]=='0'&&movable[8]=='0')||(movable[0]=='0'&&movable[1]=='0'&&movable[2]=='0'&&movable[4]=='0')||(movable[0]=='0'&&movable[3]=='0'&&movable[6]=='0'&&movable[4]=='0')||(movable[3]=='0'&&movable[2]=='0'&&movable[5]=='0'&&movable[8]=='0')||(movable[4]=='0'&&movable[6]=='0'&&movable[7]=='0'&&movable[8]=='0')||(movable[0]=='0'&&movable[1]=='0'&&movable[2]=='0'&&movable[7]=='0')||(movable[2]=='0'&&movable[5]=='0'&&movable[4]=='0'&&movable[8]=='0')||(movable[0]=='0'&&movable[3]=='0'&&movable[6]=='0'&&movable[5]=='0')){
			if((immovable[1]=='1'&&immovable[6]=='1'&&immovable[7]=='1'&&immovable[8]=='1')||(immovable[0]=='1'&&immovable[1]=='1'&&immovable[2]=='1'&&immovable[4]=='1')||(immovable[0]=='1'&&immovable[3]=='1'&&immovable[6]=='1'&&immovable[4]=='1')||(immovable[2]=='1'&&immovable[5]=='1'&&immovable[3]=='1'&&immovable[8]=='1')||(immovable[4]=='1'&&immovable[6]=='1'&&immovable[7]=='1'&&immovable[8]=='1')||(immovable[0]=='1'&&immovable[1]=='1'&&immovable[2]=='1'&&immovable[7]=='1')||(immovable[2]=='1'&&immovable[5]=='1'&&immovable[4]=='1'&&immovable[8]=='1')||(immovable[0]=='1'&&immovable[3]=='1'&&immovable[6]=='1'&&immovable[5]=='1')){
                        Print(immovable);
                    }
                    else{
                        printf("NO\n");
                    }
                }
                //case 13:movable matrix has five '2'(three horizontal & two at left/right)
                else if((movable[1]=='0'&&movable[2]=='0'&&movable[4]=='0'&&movable[5]=='0')||(movable[0]=='0'&&movable[1]=='0'&&movable[3]=='0'&&movable[4]=='0')||(movable[3]=='0'&&movable[4]=='0'&&movable[6]=='0'&&movable[7]=='0')||(movable[4]=='0'&&movable[5]=='0'&&movable[7]=='0'&&movable[8]=='0')){
                    if((immovable[1]=='1'&&immovable[2]=='1'&&immovable[4]=='1'&&immovable[5]=='1')||(immovable[0]=='1'&&immovable[1]=='1'&&immovable[3]=='1'&&immovable[4]=='1')||(immovable[3]=='1'&&immovable[4]=='1'&&immovable[6]=='1'&&immovable[7]=='1')||(immovable[4]=='1'&&immovable[5]=='1'&&immovable[7]=='1'&&immovable[8]=='1')){
                        Print(immovable);
                    }
                    else{
                        printf("NO\n");
                    }
                }
            }
            else if(movable_full==6){
                //case 14:movable matrix has six '2'(three horizontal *2)
                if((movable[0]=='0'&&movable[1]=='0'&&movable[2]=='0')||(movable[6]=='0'&&movable[7]=='0'&&movable[8]=='0')||(movable[0]=='0'&&movable[3]=='0'&&movable[6]=='0')||(movable[2]=='0'&&movable[5]=='0'&&movable[8]=='0')){
                    if((immovable[0]=='1'&&immovable[1]=='1'&&immovable[2]=='1')||(immovable[6]=='1'&&immovable[7]=='1'&&immovable[8]=='1')||(immovable[0]=='1'&&immovable[3]=='1'&&immovable[6]=='1')||(immovable[2]=='1'&&immovable[5]=='1'&&immovable[8]=='1')){
                        Print(immovable);
                    }
                    else{
                        printf("NO\n");
                    }
                }
		//case 15:movable matrix has six '2'(3+2+1)
                else if((movable[0]=='0'&&movable[1]=='0'&&movable[3]=='0')||(movable[3]=='0'&&movable[6]=='0'&&movable[7]=='0')||(movable[5]=='0'&&movable[7]=='0'&&movable[8]=='0')||(movable[1]=='0'&&movable[2]=='0'&&movable[5]=='0')){
                    if((immovable[0]=='1'&&immovable[1]=='1'&&immovable[3]=='1')||(immovable[3]=='1'&&immovable[6]=='1'&&immovable[7]=='1')||(immovable[5]=='1'&&immovable[7]=='1'&&immovable[8]=='1')||(immovable[1]=='1'&&immovable[2]=='1'&&immovable[5]=='1')){
                        Print(immovable);
                    }
                    else{
                        printf("NO\n");
                    }
                }
                //case 16:movable matrix has six '2'(3+1+2 at right)
                else if((movable[0]=='0'&&movable[3]=='0'&&movable[4]=='0')||(movable[4]=='0'&&movable[6]=='0'&&movable[7]=='0')||(movable[4]=='0'&&movable[5]=='0'&&movable[8]=='0')||(movable[1]=='0'&&movable[2]=='0'&&movable[4]=='0')){
                    if((immovable[0]=='1'&&immovable[3]=='1'&&immovable[4]=='1')||(immovable[4]=='1'&&immovable[6]=='1'&&immovable[7]=='1')||(immovable[4]=='1'&&immovable[5]=='1'&&immovable[8]=='1')||(immovable[1]=='1'&&immovable[2]=='1'&&immovable[4]=='1')){
                        Print(immovable);
                    }
                    else{
                        printf("NO\n");
                    }
                }
                //case 17:movable matrix has six '2'(3+1+2 at left)
                else if((movable[2]=='0'&&movable[4]=='0'&&movable[5]=='0')||(movable[0]=='0'&&movable[1]=='0'&&movable[4]=='0')||(movable[3]=='0'&&movable[4]=='0'&&movable[6]=='0')||(movable[4]=='0'&&movable[7]=='0'&&movable[8]=='0')){
                    if((immovable[2]=='1'&&immovable[4]=='1'&&immovable[5]=='1')||(immovable[0]=='1'&&immovable[1]=='1'&&immovable[4]=='1')||(immovable[3]=='1'&&immovable[4]=='1'&&immovable[6]=='1')||(immovable[4]=='1'&&immovable[7]=='1'&&immovable[8]=='1')){
                        Print(immovable);
                    }
                    else{
                        printf("NO\n");
                    }
                }
                else{
                    printf("NO\n");
                }
	}
            else if(movable_full==7){
                //case 18:movable matrix has seven '2'(3*2+1 at left)
                if((movable[1]=='0'&&movable[2]=='0')||(movable[0]=='0'&&movable[3]=='0')||(movable[6]=='0'&&movable[7]=='0')||(movable[5]=='0'&&movable[8]=='0')){
                    if((immovable[1]=='1'&&immovable[2]=='1')||(immovable[0]=='1'&&immovable[3]=='1')||(immovable[6]=='1'&&immovable[7]=='1')||(immovable[5]=='1'&&immovable[8]=='1')){
                        Print(immovable);
                    }
                    else{
                        printf("NO\n");
                    }
                }
                //case 19:movable matrix has seven '2'(3*2+1 at middle)
                else if((movable[0]=='0'&&movable[2]=='0')||(movable[0]=='0'&&movable[6]=='0')||(movable[6]=='0'&&movable[8]=='0')||(movable[2]=='0'&&movable[8]=='0')){
                    if((immovable[0]=='1'&&immovable[2]=='1')||(immovable[0]=='1'&&immovable[6]=='1')||(immovable[6]=='1'&&immovable[8]=='1')||(immovable[2]=='1'&&immovable[8]=='1')){
                        Print(immovable);
                    }
                    else{
                        printf("NO\n");
                    }
                }
                //case 20:movable matrix has seven '2'(3*2+1 at right)
                else if((movable[0]=='0'&&movable[1]=='0')||(movable[3]=='0'&&movable[6]=='0')||(movable[7]=='0'&&movable[8]=='0')||(movable[2]=='0'&&movable[5]=='0')){
                    if((immovable[0]=='1'&&immovable[1]=='1')||(immovable[3]=='1'&&immovable[6]=='1')||(immovable[7]=='1'&&immovable[8]=='1')||(immovable[2]=='1'&&immovable[5]=='1')){
                        Print(immovable);
                    }
                    else{
                        printf("NO\n");
                    }
                }
		//case 21:movable matrix has seven '2'(3*2+�� at right)
                else if((movable[0]=='0'&&movable[3]=='0')||(movable[6]=='0'&&movable[7]=='0')||(movable[5]=='0'&&movable[8]=='0')||(movable[1]=='0'&&movable[2]=='0')){
                    if((immovable[0]=='1'&&immovable[3]=='1')||(immovable[6]=='1'&&immovable[7]=='1')||(immovable[5]=='1'&&immovable[8]=='1')||(immovable[1]=='1'&&immovable[2]=='1')){
                        Print(immovable);
                    }
                    else{
                        printf("NO\n");
                    }
                }
                //case 22:movable matrix has seven '2'(3*2+�� at left)
                else if((movable[2]=='0'&&movable[5]=='0')||(movable[0]=='0'&&movable[1]=='0')||(movable[3]=='0'&&movable[6]=='0')||(movable[7]=='0'&&movable[8]=='0')){
                    if((immovable[2]=='1'&&immovable[5]=='1')||(immovable[0]=='1'&&immovable[1]=='1')||(immovable[3]=='1'&&immovable[6]=='1')||(immovable[7]=='1'&&immovable[8]=='1')){
                        Print(immovable);
                    }
                    else{
                        printf("NO\n");
                    }
                }
                //case 23:movable matrix has seven '2'(3*2+�� at left+�� at right)
                else if((movable[1]=='0'&&movable[4]=='0')||(movable[3]=='0'&&movable[4]=='0')||(movable[4]=='0'&&movable[7]=='0')||(movable[4]=='0'&&movable[5]=='0')){
                    if((immovable[1]=='1'&&immovable[4]=='1')||(immovable[3]=='1'&&immovable[4]=='1')||(immovable[4]=='1'&&immovable[7]=='1')||(immovable[4]=='1'&&immovable[5]=='1')){
                        Print(immovable);
                    }
                    else{
                        printf("NO\n");
                    }
                }
                else{
                    printf("NO\n");
                }
            }
	else{
                printf("NO\n");
            }
        }
        else{  //cannot match
            printf("NO\n");
        }
    }
    return 0;
}
                     
