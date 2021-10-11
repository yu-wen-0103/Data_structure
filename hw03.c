#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#define     Maxword 100

struct  node{
    char    word[Maxword];
    int     appear;
    int     print_index;
    char    punctuation;
    struct  node    *next;
    struct  node    *prev;
};

struct  node    *findsame_insert(struct node *head,char *input){
    struct  node    *current=head;
    struct  node    *newnode=malloc(sizeof(struct node));
    if(input[strlen(input)-1]=='.'){
        input[strlen(input)-1]='\0';
        newnode->punctuation='.';
    }
    else if(input[strlen(input)-1]==','){
        input[strlen(input)-1]='\0';
        newnode->punctuation=',';
    }
    else{
        newnode->punctuation='\0';
    }
    strcpy(newnode->word,input);
    newnode->appear=1;
    newnode->print_index=0;
    newnode->prev=NULL;
    newnode->next=NULL;
    int     same=0,index=1,find_index=0;

    if(head==NULL){
        head=newnode;
        printf("%s",head->word);
    }
    else{
        while(current->next!=NULL){
            current=current->next;
        }

        while(current->prev!=NULL){
            if(current->appear==1){
                if(strcmp(current->word,input)==0){
                    same=1;
                    find_index=index;
                    current->appear++;
                    current=current->prev;
                }
                else{
                    index++;
                    current=current->prev;
                }
            }
            else{
                current=current->prev;
            }
        }
        if(current->appear==1){
            if(strcmp(current->word,input)==0){
                same=1;
                find_index=index;
                current->appear++;
            }
            else{
                index++;
            }
        }
        while(current->next!=NULL){
            current=current->next;
        }
        if(same==1){  //same words appear
            newnode->print_index=find_index;
        }
        current->next=newnode;
        newnode->prev=current;
        //printf
        if(newnode->print_index!=0){
            if(newnode->punctuation=='\0'){
                printf(" %d",newnode->print_index);
            }
            else{
                printf(" %d%c",newnode->print_index,newnode->punctuation);
            }
        }
        else{
            if(newnode->punctuation=='\0'){
                printf(" %s",newnode->word);
            }
            else{
                printf(" %s%c",newnode->word,newnode->punctuation);
            }
        }
    }
    return head;
}

int     main(){
    struct  node    *data=NULL;
    char    input[Maxword];

    while(scanf("%s",input)!=EOF){
        data=findsame_insert(data,input);
    }
    return 0;
}

