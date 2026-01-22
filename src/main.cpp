#include<iostream>
using namespace std;

string target;
string scan;

void start(){
cout<<"\033[38;2;255;29;0m";
cout<<"\033[2J\033[H";
cout<<R"(
▓█████ ▒███████▒ ███▄ ▄███▓ ▄▄▄       ██▓███  
▓█   ▀ ▒ ▒ ▒ ▄▀░▓██▒▀█▀ ██▒▒████▄    ▓██░  ██▒
▒███   ░ ▒ ▄▀▒░ ▓██    ▓██░▒██  ▀█▄  ▓██░ ██▓▒
▒▓█  ▄   ▄▀▒   ░▒██    ▒██ ░██▄▄▄▄██ ▒██▄█▓▒ ▒
░▒████▒▒███████▒▒██▒   ░██▒ ▓█   ▓██▒▒██▒ ░  ░
░░ ▒░ ░░▒▒ ▓░▒░▒░ ▒░   ░  ░ ▒▒   ▓▒█░▒▓▒░ ░  ░
 ░ ░  ░░░▒ ▒ ░ ▒░  ░      ░  ▒   ▒▒ ░░▒ ░     
   ░   ░ ░ ░ ░ ░░      ░     ░   ▒   ░░       
   ░  ░  ░ ░           ░         ░  ░         
       ░                                      

)";

cout<<"\033[0m";
cout<<"\n\t...Scanning made EZ...\n";
return;
}

void selectTarget(){

cout<<"\n";

cout<<"Enter your target: ";
getline(cin,target);
return;

}

void scanType(){
int choice;
cout<<"\033[2J\033[H";
cout<<"1. Quick Scan";
cout<<"\t2. OS Detection";
cout<<"\n3. Discovery";
cout<<"\t4. Stealth Scan";
cout<<"\n5. Intense Scan";

cout<<"\nChoose Type: ";
cin>>choice;
cout<<"\n";
if(choice==1){

scan="nmap -F " + target;
}
else if(choice==2){
scan="nmap -O " + target;
}
else if(choice==3){
scan ="nmap -v " + target +"/24";
}
else if(choice==4){
scan="nmap -v -sS " +target;
}
else if(choice==5){
scan="nmap -A -v "+target;
}
else{
cout<<"\ninvalid option!";
return;
}
return;
}


 
int main(){
start();
selectTarget();
int choice;
do{

cout<<"\n\n\tYour current target is: ";
cout<<"\033[38;2;255;29;0m";
cout<<target;
cout<<"\033[0m";

cout<<"\n1. Change Target";
cout<<"\n2. Choose Scan Type";
cout<<"\n3. Exit";
cout<<"\nSelect: ";
cin>>choice;

if(choice==1){
selectTarget();
main();
return 0;
}

else if(choice==2){
scanType();
system(scan.c_str());
break;
}

}while(choice!=3 && choice!=2);
cout<<"\nGoodBye :)";
return 0;
}
