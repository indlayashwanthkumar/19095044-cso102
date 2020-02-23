#include<stdio.h>
#include<string.h>
struct listnode{
    char data[100];
    struct listnode *prev;
    struct listnode *next;
    int type;
}*head=0,*tmp,*newnode,*tmp2;
void add(char *d,int t){
    if(head==0){
        newnode=(struct listnode *)malloc(sizeof(struct listnode));
        head=tmp=newnode;
        tmp->prev=0;
    }
    else {
        newnode=(struct listnode *)malloc(sizeof(struct listnode));
        newnode->prev=tmp;
        tmp->next=newnode;
        tmp=newnode;
    }
    strcpy(newnode->data,d);
    newnode->type=t;
    newnode->next=0;
}

void del(){
    tmp=head;
    while(tmp!=0){
        if(tmp->type==1){
                tmp2=tmp;
                if(tmp2==head) head=head->next;
                else tmp2->prev->next=tmp2->next;
                free(tmp2);
            }
        tmp=tmp->next;
    }
}
void display(){
    tmp=head;
    while(tmp!=0){
        printf("%s ",tmp->data);
        tmp=tmp->next;
    }
    printf("\n");
}
int main(){
    int n,m;
    char command[10],country[100],type[5];
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%s",command);
        if(strcmp(command,"ADD")==0){
            scanf("%s",country);
            scanf("%s",type);
            if(strcmp(type,"P")==0) add(country,1);
            else add(country,0);
        }
        else if(strcmp(command,"DEL")==0) del();
        else if(strcmp(command,"DISPLAY")==0) display();
    }
    return 0;
}
