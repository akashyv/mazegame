#include<iostream>
using namespace std;
struct node {
  int x;
  int y;
  struct node *next;
};

struct node *insert(struct node *start,int x1,int y1)
{
struct node *n,*ptr;
n=new node;
n->x=x1;
n->y=y1;
n->next=NULL;
  if(start==NULL){
    start=n;

  }
  else{
    ptr=start;
    while(ptr->next!=NULL){
      ptr=ptr->next;
    }
    ptr->next=n;

  }
  return start;
}
struct node *del(struct node *start)
{
  struct node *ptr;
  ptr=start;
  start=start->next;
  delete ptr;
  return start;
}



int find(int sx,int sy,int dx,int dy,char maze[10][20]){
  struct node *start,*ptr;
  start=NULL;
  start=insert(start,sx,sy);
int flag=0;
maze[sx][sy]='*';
  while(flag==0){
    if(maze[start->x +1][start->y]!='x'&& maze[start->x+1][start->y]!='*'&& maze[start->x +1][start->y]!='#')
    {
      if(start->x+1!=dx||start->y!=dy){
        maze[start->x+1][start->y]='#';
        start=insert(start,start->x+1,start->y);
      }
      else{
        flag=1;break;
      }
    }
    if(maze[start->x -1][start->y]!='x'&& maze[start->x-1][start->y]!='*'&& maze[start->x -1][start->y]!='#')
    {
      if(start->x-1!=dx||start->y!=dy){
        maze[start->x-1][start->y]='#';
        start=insert(start,start->x-1,start->y);

      }
      else{
        flag=1;
		break;
      }
    }
    if(maze[start->x ][start->y +1]!='x'&& maze[start->x][start->y+1]!='*'&& maze[start->x ][start->y+1]!='#')
    {
      if(start->x!=dx||start->y+1!=dy){
        maze[start->x][start->y+1]='#';
        start=insert(start,start->x,start->y+1);

      }
      else{
        flag=1;break;
      }
    }
    if(maze[start->x ][start->y -1]!='x'&& maze[start->x][start->y-1]!='*'&& maze[start->x ][start->y-1]!='#')
    {
      if(start->x!=dx||start->y-1!=dy){
        maze[start->x][start->y-1]='#';
        start=insert(start,start->x,start->y-1);

      }
      else{
        flag=1;break;
      }
    }

    maze[start->x][start->y]='*';

    start=del(start);
    if(start==NULL){
      flag=2;
    }

  }

  if (flag==2){
    return 0;
  }
  else if(flag==1){
    return 1;
  }
return 0;
}


void print(char mat[10][20],int x1,int y1,int x2,int y2){

  mat[x1][y1]='o';
  mat[x2][y2]='@';


  int i,j;
  for(i=0;i<10;i++){
    for(j=0;j<20;j++){
      printf("%c",mat[i][j] );
    }printf("\n" );
  }
  mat[x1][y1]=' ';

}


int play(char maze[10][20],char game[10][20],int sx,int sy,int dx,int dy){

int score=0;
char move;
while(sx!=dx||sy!=dy){
print(game,sx,sy,dx,dy);
  cin>>move;
  if(move=='w'){
    if(game[sx-1][sy]!='x'){
      if(maze[sx-1][sy]=='*'){
        score++;
      }
      else if(maze[sx-1][sy]=='#'){
        score--;
      }
      else{
        score-=4;
      }
      sx-=1;
    }
  }
  else if(move=='s'){
    if(game[sx+1][sy]!='x'){
      if(maze[sx+1][sy]=='*'){
        score++;
      }
      else if(maze[sx+1][sy]=='#'){
        score--;
      }
      else{
        score-=4;
      }
      sx+=1;
      
    }
  }
else if(move=='a'){
  if(game[sx][sy-1]!='x'){
    if(maze[sx][sy-1]=='*'){
      score++;
    }
    else if(maze[sx][sy-1]=='#'){
      score--;
    }
    else{
      score-=4;
    }
    sy-=1;
  }
}
else if(move=='d'){
  if(game[sx][sy+1]!='x'){
    if(maze[sx][sy+1]=='*'){
      score++;
    }
    else if(maze[sx][sy+1]=='#'){
      score--;
    }
    else{
      score-=4;
    }
    sy+=1;
  }
}

}
return score;

}


int main()
{
	
char maze[10][20],game[10][20];
  int k,i,j;
  for(i=0;i<10;i++){
    for(j=0;j<20;j++){
      maze[i][j]=' '; game[i][j]=' ';
    }
  }
  for(i=0;i<10;i++){
    maze[i][0]='x';game[i][0]='x';
  }
  for(i=0;i<20;i++){
    maze[0][i]='x';game[0][i]='x';
  }
  for(i=0;i<10;i++){
    maze[i][19]='x';game[i][19]='x';
  }
  for(i=0;i<20;i++){
    maze[9][i]='x';game[9][i]='x';
  }
  maze[2][1]='x';game[2][1]='x';
  maze[2][2]='x';game[2][2]='x';
maze[1][5]='x';game[1][5]='x';
maze[2][5]='x';game[2][5]='x';
maze[3][5]='x';game[3][5]='x';
maze[3][6]='x';game[3][6]='x';
maze[3][7]='x';game[3][7]='x';
maze[3][18]='x';game[3][18]='x';
maze[3][17]='x';game[3][17]='x';
maze[3][16]='x';game[3][16]='x';
maze[4][16]='x';game[4][16]='x';
maze[4][15]='x';game[4][15]='x';
maze[4][14]='x';game[4][14]='x';
maze[5][14]='x';game[5][14]='x';
maze[5][16]='x';game[5][16]='x';
maze[8][5]='x';game[8][5]='x';

maze[8][6]='x';game[8][6]='x';
maze[6][16]='x';game[6][16]='x';
maze[6][10]='x';game[6][10]='x';
maze[6][9]='x';game[6][9]='x';
maze[6][8]='x';game[6][8]='x';
maze[6][7]='x';game[6][7]='x';
int sx,sy,dx,dy;
cout<<"Enter the coordinates of source(1-5) and destination(1-8)"<<endl;
cin>>sx>>sy>>dx>>dy;
k=find(sx,sy,dx,dy,maze);

for(i=0;i<10;i++){
  for(j=0;j<20;j++){
    cout<<maze[i][j];
  }cout<<endl;
}



if(k==1){
i=  play(maze,game,sx,sy,dx,dy);
  cout<<"score is "<<i;
}
else{
  cout<<" it does not have a path";
}
}

