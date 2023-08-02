#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define size 2
//Structure
int i;
struct cust{
    int  acc_no;
    int  pass;
    float balance;
}test;

struct cust customer[size];
//Global declaration
int login_option;

//struct cust customer[size];



//Functions
void login();
void menu();
void mainMenu();
void checkBalance(float balance);
float moneyDeposit(float balance);
float moneyWithdraw(float balance);
void menuExit(int);
void errorMessage();
void file(int);
void file0();
void file1();


//Main Code
int main() 
{

// initializing values  

customer[0].acc_no=10001;
customer[0].pass=2003;

customer[1].acc_no=10002;
customer[1].pass=2003;


    //scanning values from txt files

    FILE *pf;
    pf=fopen("10001.txt","r");
    if(pf==NULL){

    }else{
        fscanf(pf,"%f",&customer[i].balance);
    }
fclose(pf);

FILE *pF;
    pF=fopen("10002.txt","r");
    if(pF==NULL){

    }else{
        fscanf(pF,"%f",&customer[1].balance);
    }
fclose(pF);


    //Local Declarations
    int option;
    int choose;

    bool again = true;

    here:
    menu();

    for(i=0;i<size;i++){
    
        if(test.acc_no==customer[i].acc_no && test.pass==customer[i].pass){

        while (again) {
        
            mainMenu();

            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
            printf("Your Selection:\t");
            scanf("%d", &option);


            switch (option) {
                case 1:
                {	
                    system("CLS");
                    checkBalance(customer[i].balance);
                    break;
                }
                case 2:
                {
                    system("CLS");
                    customer[i].balance = moneyDeposit(customer[i].balance);
                    break;
                }
                case 3:
                {
                    system("CLS");
                    customer[i].balance = moneyWithdraw(customer[i].balance);
                    break;
                }
                case 4:
                {
            	    system("CLS");
                    menuExit(i);
                    return 0;
                }
                default:
                    errorMessage();
                    break;
            }   

            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("Would you like to do another transaction:\n");
            printf("< 1 > Yes\n");
            printf("< 2 > No\n");
            scanf("%d", &choose);

            system("CLS");

            if (choose == 2)
            {
                again = false;
                menuExit(i);
            }   

        }

     }

    }
    return 0;
}//main code



// Functions


void menu()
{
    printf("******************Hello!*******************\n");
    printf("**********Welcome to ATM Banking***********\n\n");
    printf("****Please choose one of the options below****\n\n");
    printf("< 1 >  LOGIN \n");
    printf("< 2 >  Exit\n\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("Your Selection:\t");
    scanf("%d", &login_option);

     switch (login_option) {
            case 1:
            {	
                login();
                return;
            }
            case 2:
            {
                menuExit(i);
                return;
            }
           
            default:
                errorMessage();
                break;
        }
        return;

}//menu

void login()
{   
    printf("Enter Account Number: ");
    scanf("%d",&test.acc_no);
    fflush(stdin);
    printf("Enter Password : ");
    scanf("%d",&test.pass);
    fflush(stdin);
}//login


void mainMenu() {

    printf("******************Hello!*******************\n");
    printf("**********Welcome to ATM Banking***********\n\n");
    printf("****Please choose one of the options below****\n\n");
    printf("< 1 >  Check Balance\n");
    printf("< 2 >  Deposit\n");
    printf("< 3 >  Withdraw\n");
    printf("< 4 >  Exit\n\n");

}//Main Menu

void checkBalance(float balance) {
    printf("You Choose to See your Balance\n");
    printf("\n\n****Your Available Balance is:   $%.2f\n\n", balance);

}//Check Balance

float moneyDeposit(float balance) {
    float deposit;
    printf("You choose to Deposit a money\n");
    printf("$$$$Your Balance is: $%.2f\n\n", balance);
    printf("****Enter your amount to Deposit\n");
    scanf("%f", &deposit);


    balance += deposit;

    printf("\n****Your New Balance is:   $%.2f\n\n", balance);
    return balance;

}//money deposit

float moneyWithdraw(float balance) {
    float withdraw;
    bool back = true;

    printf("You choose to Withdraw a money\n");
    printf("$$$$Your Balance is: $%.2f\n\n", balance);

    while (back) {
    printf("Enter your amount to withdraw:\n");
    scanf("%f", &withdraw);


    if (withdraw < balance) {
        back = false;
        balance -= withdraw;
        printf("\n$$$$Your withdrawing money is:  $%.2f\n", withdraw);
        printf("****Your New Balance is:   $%.2f\n\n", balance);

    }

        else  {

        printf("+++You don't have enough money+++\n");
        printf("Please contact to your Bank Customer Services\n");
        printf("****Your Balance is:   $%.2f\n\n", balance);

    }
    }
    return balance;


}//money withdraw

void file(int i)
{
    FILE *fp;
    
    fp=fopen("receipt.txt","w");
    if(fp == NULL){
        printf("Recipt cannot be printed !!!");
    }else{
        fprintf(fp,"Closing Balance : %f. ",customer[i].balance);
    }

    fclose(fp);
}

void file0(){
    FILE *pf;
    
    pf=fopen("10001.txt","w");
    if(pf==NULL){

    }else{
        fprintf(pf,"%f",&customer[0].balance);
    }
fclose(pf);    
}//Saving closing balance of customer1

void file1(){

FILE *pF;
    pF=fopen("10002.txt","r");
    if(pF==NULL){

    }else{
        fscanf(pF,"%f",&customer[1].balance);
    }
fclose(pF);

}//Saving closing balance of customer2

void menuExit(int i) {
    
    printf("--------------Take your receipt!!!------------------\n");
    printf("-----Thank you for using ATM Banking Machine!!!-----\n");
    file(i);
    file0();
    file1();
}//exit menu

void errorMessage() {

    printf("+++!!!You selected invalid number!!!+++\n");
    
}//error message