#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

float oneWorkmassstrokethrust(float mas,float  n){
float orm=0;
    if(n>0 ||mas>0){
         orm=mas*(1+(n/30));//Epler
         return orm;
}
     else return 0;
}
float oneWorkmasslyingdown(float mas, float n){
float orm=0;
    if(n>0 || mas>0){
     orm =mas*(36/(36-n));//Bzuchki
     return orm;
}
    else return 0;
}
float oneWorkmasssittingbarbell(float mas, float n){
    float orm1;
if (n>0 || mas>0){
      orm1=(mas*(1 + 0.025 *n )); //O'Connor
      return orm1;
}
      else return 0;
}
void myInfo(float mas, float n, FILE *fileIn){
    fileIn=fopen("data.txt","a");
printf("One repeat maximum mass with at the state of the draft: %.2f kg\n",oneWorkmassstrokethrust(mas,n));
printf("One repeat maximum mass at the bench lying down: %.2f kg\n",oneWorkmasslyingdown(mas,n));
printf("One repeat maximum weight when squatted with a barbell:%.2f kg\n",oneWorkmasssittingbarbell(mas,n));
fprintf(fileIn,"One repeat maximum mass with a stationary thrust: %.2f kg\n",oneWorkmassstrokethrust(mas,n));
fprintf(fileIn,"One repeat maximum mass at the bench lying down: %.2f kg\n",oneWorkmasslyingdown(mas,n));
fprintf(fileIn,"One repeat maximum weight when squatted with a barbell: %.2f kg\n",oneWorkmasssittingbarbell(mas,n));
}
void procentstrokethrust(int mas, int n,FILE *fileIn){
float poin=oneWorkmassstrokethrust(mas,n);
fileIn=fopen("data.txt","a");
int i, resl=0,j=0;
printf("\nPercentage relation to one repeat maximum mass at the state of the draft:\n");
fprintf(fileIn,"\nPercentage relation to one repeat maximum mass at the state of the draft:\n");
    for(i=1;i<=10;i++){
        resl=poin/10*i;
        j+=10;
    printf("%i%% - %i -%i kg\t\n",j,resl,resl+1);
    fprintf(fileIn,"%i%% - %i -%i kg\t\n",j,resl,resl+1);
}
}
void procentlyingdown(int mas, int n,FILE *fileIn){
float poin=oneWorkmasslyingdown(mas,n);
int i, resl=0,j=0;
fileIn=fopen("data.txt","a");
printf("\nPercentage relation to one repeat maximum mass at the lying down:\n");
fprintf(fileIn,"\nPercentage relation to one repeat maximum mass at the lying down:\n");
    for(i=1;i<=10;i++){
         resl=poin/10*i;
         j+=10;
    printf("%i%% - %i -%i kg\t\n",j,resl,resl+1);
    fprintf(fileIn,"%i%% - %i -%i kg\n",j,resl,resl+1);
}
}
void procentsittingbarbell(int mas, int n,FILE *fileIn){
float poin=oneWorkmasssittingbarbell(mas,n);
fileIn=fopen("data.txt","a");
int i, resl=0,j=0;
printf("\nPercentage relation to one repeat maximum mass at the sitting barbell:\n");
fprintf(fileIn,"\nPercentage relation to one repeat maximum mass at the sitting barbell:\n");
     for(i=1;i<=10;i++){
       resl=poin/10*i;
        j+=10;
        printf("%i%% - %i -%i kg\t\n",j,resl,resl+1);
        fprintf(fileIn,"%i%% - %i -%i kg\t\n",j,resl,resl+1);
}
}
void procentRepit(FILE *fileIn){
    fileIn=fopen("data.txt","a");
int i, j=0;
int n=100,s=5,sum;
printf("\nPercentage of weight to number of repetitions:\n");
fprintf(fileIn,"\nPercentage of weight to number of repetitions:\n");
    for(i=0;i<=20;i+=2){
    sum=n/s-i;
    j+=10;
if(sum==0){
   break;
}
printf("%i%%-%i-%i repeats\n",j,sum-1,sum);
fprintf(fileIn,"%i%%-%i-%i repeats\n",j,sum-1,sum);
}
}
 void recomInfo (FILE *fileIn){
 int num=100,i,resalt,j=10;
fileIn=fopen("data.txt","a");
 for(i=20;i<=30;i+=5){
 resalt=num/i;
   printf("Recomendashon number of set for one training:%i%%-%i%% - %i-%i set\n",j,j+30,resalt-1,resalt);
   fprintf(fileIn,"\nRecomendashon number of set for one training:%i%%-%i%% - %i-%i set\n",j,j+30,resalt-1,resalt);
   j+=30;
}
}
void inforForweek(FILE *fileIn){
 int num=100,i,resalt,j=10;
 fileIn=fopen("data.txt","a");
     for(i=25;i<=35;i+=5){
         resalt=num/i;
   printf("Recomendashon number workouts for of  week :%i%%-%i%% - %i-%i training\n",j,j+30,resalt-1,resalt);
   fprintf(fileIn,"\nRecomendashon number workouts for of  week :%i%%-%i%% - %i-%i training\n",j,j+30,resalt-1,resalt);
  j+=30;
}
}
void myIntroduction(){
printf("Hello.This program will help you in weight training and training in three basic exercises, such as:\n");
printf("-bench press,\n");
printf("-stroke thrust,\n");
printf("-squatting with a barbell.\n");
printf("Please keep your data.\n");
printf("Press any key to continue!\n");
getch();
system("cls");
}
void myFunction(int mas, int repit,FILE *fileIn){
printf("\n");
myInfo(mas,repit,fileIn);
printf("Press any key to continue!\n");
getch();
system("cls");
procentstrokethrust(mas, repit,fileIn);
printf("Press any key to continue!\n");
getch();
procentlyingdown(mas,repit,fileIn);
printf("Press any key to continue!\n");
getch();
procentsittingbarbell(mas,repit,fileIn);
printf("Press any key to continue!\n");
getch();
system("cls");
printf("Recommended information.");
procentRepit(fileIn);
printf("Press any key to continue!\n");
getch();
printf("\n");
recomInfo(fileIn);
printf("Press any key to continue!\n");
getch();
printf("\n");
inforForweek(fileIn);
}

int main(){
int repit;
int mas;
FILE *fileIn=fopen("data.txt","w");
myIntroduction();

while(1){
printf("Keep the mass of the projectile: ");
if( scanf("%d",&mas)!=1 ){
    printf("You input incorect data!!!\n");
    fflush(stdin);
    continue;
}
else if(mas<10 || mas>550){
    printf("You input incorect data!!!\n");
    fflush(stdin);
    continue;
}
else break;
}
fprintf(fileIn,"Keep the mass of the projectile:%d\n",mas);

while(1){
  printf("Keep the number of repetitions: ");
if(scanf("%d",&repit)!=1){
  printf("You input incorect data!!!\n");
  fflush(stdin);
  continue;
}
else if(repit<1||repit>20){
    printf("You input incorect data!!!\n");
    fflush(stdin);
    continue;
}
    else break;
}
fprintf(fileIn,"Keep the number of repetitions:%d\n",repit);
myFunction(mas,repit,fileIn);
fclose(fileIn);
return 0;
}
