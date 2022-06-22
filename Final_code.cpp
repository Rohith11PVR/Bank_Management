#include <bits/stdc++.h>
#include <windows.h>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <string>
#include <regex>

using namespace std;

void printStrongNess(string& input)
{
    int n = input.length();
    bool hasLower = false, hasUpper = false;
    bool hasDigit = false, specialChar = false;
    string normalChars = "abcdefghijklmnopqrstu"
        "vwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
 
    for (int i = 0; i < n; i++) {
        if (islower(input[i]))
            hasLower = true;
        if (isupper(input[i]))
            hasUpper = true;
        if (isdigit(input[i]))
            hasDigit = true;
 
        size_t special = input.find_first_not_of(normalChars);
        if (special != string::npos)
            specialChar = true;
    }
    cout << "Strength of password:-";
    if (hasLower && hasUpper && hasDigit &&
        specialChar && (n >= 8))
        cout << "Strong" << endl;
    else if ((hasLower || hasUpper) &&
             specialChar && (n >= 6))
        cout << "Moderate" << endl;
    else
        cout << "Weak" << endl;
}

bool isNumber(string s)
{
    if(s.length()>9){
        return false;
    }
    for (int i = 0; i < s.length(); i++){
        if (isdigit(s[i]) == false){
            return false;
        }
    }
    return true;
}

void pattern(){
    cout<<"\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"\n                                                                              WELCOME TO                              \n"<<endl;
    cout<<"                                                                         INDIAN EXCHNAGE BANK                        \n"<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<endl;
}

string date_time(){
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y %H:%M:%S");
    auto str = oss.str();

    return str;
}

void timer(int sec)
{
    Sleep(sec*1000);
}

bool isValid(string s){
  const regex pattern("(0|91)?[7-9][0-9]{9}");
  if(regex_match(s, pattern))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isValidName(string s){
  const regex pattern("[a-zA-Z]+");
  if(regex_match(s, pattern))
  {
    return true;
  }
  else
  {
    return false;
  }
}

class BST {
	int acc;
    int balance;
    string fis_name;
    string las_name;
	BST *left, *right;

public:
	// Default constructor.
	BST();

	// Parameterized constructor.
	BST(string,string,int,int);

	// Insert function.
	BST* Insert(BST*, string,string,int,int);

	// Inorder traversal.
	void Inorder(BST*);

    void printInOrder_1(BST*);
    
};

BST ::BST()
	: acc(0)
    , fis_name("t")
    , las_name("r")
    , balance(0)
	, left(NULL)
	, right(NULL)
{
}

BST ::BST(string fname , string lname,int value, int bal)
{
    fis_name=fname;
    las_name=lname;
	acc = value;
    balance=bal;
	left = right = NULL;
}

BST* BST ::Insert(BST* root, string fname , string lname, int value, int bal)
{
	if (!root) {
		return new BST(fname,lname, value,bal);
	}

	// Insert data.
	if (bal > root->balance) {
		// Insert right node data, if the 'value'
		// to be inserted is greater than 'root' node data.

		// Process right nodes.
		root->right = Insert(root->right, fname , lname , value,bal);
	}
	else {
		// Insert left node data, if the 'value'
		// to be inserted is greater than 'root' node data.

		// Process left nodes.
		root->left = Insert(root->left, fname , lname , value,bal);
	}

	// Return 'root' node, after insertion.
	return root;
}

void BST ::Inorder(BST* root)
{
	if (!root) {
		return;
	}
	Inorder(root->left);
	cout << "  "<<root->acc<<"  "<<root->balance << endl;
	Inorder(root->right);
}

void BST :: printInOrder_1(BST*n){
    if(n != NULL){
        printInOrder_1(n->right);
        cout<<n->fis_name;
            for(int i=0;i<20-n->fis_name.length();i++){
                cout<<" ";
            }
        cout<<n->las_name;
            for(int i=0;i<20-n->las_name.length();i++){
                cout<<" ";
            }
            cout<<n->acc;
            ostringstream str1;
            str1 << n->acc;
            string geek = str1.str();

            for(int i=0;i<20-geek.length();i++){
                cout<<" ";
            }

            ostringstream str2;
            str2 << n->balance;
            string geek2 = str2.str();

            cout<<n->balance;
            for(int i=0;i<15-geek2.length();i++){
                cout<<" ";
            }
            cout<<endl;
        printInOrder_1(n->left);
    }
}

class Node2{
    public:
    int acc2;    //account number..
    string d2;   //date of transaction
    string t2;   //time of 
    int b2;      //balance
    string mode;  //deposit or withdraw
    string n2;   //first name
    string l2;   //last name
    Node2 * next2;

    Node2(int aa2,string bb2,string cc3,int dd4, string ee5,string ff6,string hh7){
        acc2=aa2;
        n2=bb2;
        l2=cc3;
        b2=dd4;
        mode=ee5;
        d2=ff6;
        t2=hh7;
        next2=NULL;
    }
};

class Node{
    public:
    Node * next;
    string first_name;
    string last_name;
    string account_type;
    string gender;
    int account_no;
    int balance;
    string password;
    string date_created;
    string time;
    Node2 * head2;
    int number_of_transactions;


    Node(string a, string b, string c, string d,int e , int f, string g, string h, string i){
        first_name=a;
        last_name=b;
        account_type=c;
        gender=d;
        account_no=e;
        balance=f;
        password=g;
        date_created=h;
        time=i;
        next=NULL;
        head2=NULL;
        number_of_transactions=0;
    }

};

class Admin{
    public :
    Node * head;
    int number_of_customers;
    int id;
    BST bun;

    Admin(){
        head=NULL;
        number_of_customers=0;
        id=0;
    }
    // a is accno , b is fname , c is lname , d is balance , e is mode , f is date , h is time 
    void insert_data_transaction(int a, string b, string c, int d, string e,string f,string h,Node * current_user){    //similar to i() and insert()...
        
        Node2 * n2 = new Node2(a,b,c,d,e,f,h);
        current_user->number_of_transactions++;
        if(current_user->head2==NULL){
            current_user->head2=n2;
            return;
        }
        Node2 * temp2 = current_user->head2;
        while(temp2->next2!=NULL){
            temp2 = temp2->next2;
        }
        temp2->next2=n2;
        return;
    }

    void display_n_transactions(Node * current_user){
        Node2 * temp2=current_user->head2; int count =1;
        cout<<"Transaction No  ";  //allocate 15 spaces..
        cout<<"Acc no    ";  //allocate 10 spaces..
        cout<<"First Name    ";//alloacte 15 spaces..
        cout<<"Last Name      "; //alloacte 15 spaces..
        cout<<"Balance            ";   //allocate 15 spaces..
        cout<<"Mode        "; //allocate 10 spaces..
        cout<<"Date of trsc  "; //alloacte 15 spaces..
        cout<<"Time of trsc  "; //alloacte 15 spaces..
        cout<<endl;
        cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
        while(temp2!=NULL){
            cout<<count;
            ostringstream str11;
            str11 << count;
            string geek11 = str11.str();
            for(int i=0;i<15-geek11.length();i++){
                cout<<" ";
            }

            cout<<temp2->acc2;
            ostringstream str12;
            str12 << temp2->acc2;
            string geek12 = str12.str();
            for(int i=0;i<10-geek12.length();i++){
                cout<<" ";
            }

            cout<<temp2->n2;
            for(int i=0;i<15-temp2->n2.length();i++){
                cout<<" ";
            }
            cout<<temp2->l2;
            for(int i=0;i<15-temp2->l2.length();i++){
                cout<<" ";
            }

            cout<<temp2->b2;
            ostringstream str13;
            str13 << count;
            string geek13 = str13.str();
            for(int i=0;i<15-geek13.length();i++){
                cout<<" ";
            }

            cout<<temp2->mode;
            for(int i=0;i<15-temp2->mode.length();i++){
                cout<<" ";
            }

            cout<<temp2->d2;
            for(int i=0;i<15-temp2->d2.length();i++){
                cout<<" ";
            }

            cout<<temp2->t2;
            count++;
            temp2=temp2->next2;
            cout<<endl;
        }
    }

    void insert_into_bst(){
        Node * temp = head;
        BST bun, *root = NULL;
        root = bun.Insert(root, temp->first_name,temp->last_name,temp->account_no,temp->balance);
        temp=temp->next;
        while(temp!=NULL){
            root = bun.Insert(root,temp->first_name,temp->last_name,temp->account_no,temp->balance);
            temp=temp->next;
        }
        cout<<"First name          ";  //allocate 20 spaces
        cout<<"Last name           ";   //allocate 20 spaces
        cout<<"Account no          ";  //allocate 20 spaces
        cout<<"Balance        ";   //allocate 15 spaces
        cout<<endl;
        cout<<"-----------------------------------------------------------------";
        cout<<endl;
        bun.printInOrder_1(root);
    }
    
    void main_menu_ret(){
        cout<<endl;
        cout<<"Press 1 to enter the Main menu"<<endl;
        cout<<"Press 2 to exit"<<endl;
        while(true){        
                cout<<"Enter : ";
                string  tu;
                cin>>tu;
                while(true){
                    if(isNumber(tu)){
                        break;
                    }
                    cout<<"Please enter a valid input : ";
                    cin>>tu;
                }
                if(tu=="1"){
                    Main_menu();
                    break;
                }
                else if(tu=="2"){
                    cout<<"You are logging out"<<endl;
                    save();
                    int n=7;
                    while(n!=0){
                        cout<<".";
                        timer(1);
                        cout<<"  ";
                        n--;
                    }
                    break;
                }
                else{
                    cout<<"Please enter a valid input"<<endl;
                }
        }
    }

    int acc_validity(int a){
        Node * temp=head;
        int flag=0;
        while(temp!=NULL){
            if(temp->account_no==a){
                cout<<"Valid account"<<endl;
                return a;
                break;
            }
            temp=temp->next;
        }
        
        cout<<"This account doesn't exist in this bank"<<endl;
        cout<<"Please enter a valid account number :";
        while(true){
            Node * temp=head;
            int k; cin>>k;
            while(temp!=NULL){
                if(temp->account_no==k){
                    //cout<<"Valid account"<<endl;
                    return k;
                    break;
                }
                temp=temp->next;
            }
            cout<<"\nThis account doesn't exist in this bank"<<endl;
            cout<<"Please enter a valid account number :";
        }
    }
    
    void insert_user(string a, string b, string c, string d,int e , int f, string g, string h, string i){
        Node * n = new Node(a,b,c,d,e,f,g,h,i);
        n->next=head;
        head=n;
        number_of_customers++;
        id++;
        return;
    }

    void display(){
        cout<<endl;
        Node*temp = head;
        cout<<"First name          ";  //allocate 20 spaces
        cout<<"Last name           ";   //allocate 20 spaces
        cout<<"Mobile Number  "; //allocate 15 spaces
        cout<<"Gender  ";     //allocate 8 spaces
        cout<<"Account no          ";  //allocate 20 spaces
        cout<<"Balance        ";   //allocate 15 spaces
        cout<<"Date created          "; //allocate 25 spaces
        cout<<"Time created          "<<endl; //allocate 25 spaces
        cout<<"---------------------------------------------------------------------------------------------------------------------------------------"<<endl;


        while(temp!=NULL){   

            cout<<temp->first_name;
            for(int i=0;i<20-temp->first_name.length();i++){
                cout<<" ";
            }
           

            cout<<temp->last_name;
            for(int i=0;i<20-temp->last_name.length();i++){
                cout<<" ";
            }
            

            cout<<temp->account_type;
            for(int i=0;i<15-temp->account_type.length();i++){
                cout<<" ";
            }
            

            cout<<temp->gender;
            for(int i=0;i<7;i++){
                cout<<" ";
            }
            

            cout<<temp->account_no;
            ostringstream str1;
            str1 << temp->account_no;
            string geek = str1.str();

            for(int i=0;i<20-geek.length();i++){
                cout<<" ";
            }

            ostringstream str2;
            str2 << temp->balance;
            string geek2 = str2.str();

            cout<<temp->balance;
            for(int i=0;i<15-geek2.length();i++){
                cout<<" ";
            }
            

            cout<<temp->date_created;
            for(int i=0;i<22-temp->date_created.length();i++){
                cout<<" ";
            }
            

            cout<<temp->time;
            temp = temp->next;
            cout<<endl;
        }
        cout<<endl;
        main_menu_ret();
        
    }

    void show_balance(int a){ //a is the account no..
        a=acc_validity(a);
        Node * temp = head; 
        while(temp->account_no!=a){
            temp=temp->next;
        }
        cout<<"\nHello Mr."<<temp->first_name<<" "<<temp->last_name<<endl;
        cout<<"\nYour present balance is :"<<temp->balance<<endl;
        
    }

    void show_balance_2(int a){
        Node * temp = head; 
        while(temp->account_no!=a){
            temp=temp->next;
        }
        cout<<"\nHello Mr."<<temp->first_name<<" "<<temp->last_name<<endl;
        cout<<"\nYour present balance is :"<<temp->balance<<endl;

    }
    
    void acc_enquiry_1(int a){
        cout<<endl;
        Node * temp = head; 
        int k; 
        while(temp->account_no!=a){
            temp=temp->next;
        }
        cout<<"First name          ";  //allocate 20 spaces
        cout<<"Last name           ";   //allocate 20 spaces
        cout<<"Mobile Number  "; //allocate 15 spaces
        cout<<"Gender  ";     //allocate 8 spaces
        cout<<"Account no          ";  //allocate 20 spaces
        cout<<"Balance        ";   //allocate 15 spaces
        cout<<"Date created          "; //allocate 20 spaces
        cout<<"Time created           "<<endl; //allocate 20 spaces
        cout<<"--------------------------------------------------------------------------------------------------------------------------------------------"<<endl;


            cout<<temp->first_name;
            for(int i=0;i<20-temp->first_name.length();i++){
                cout<<" ";
            }
            

            cout<<temp->last_name;
            for(int i=0;i<20-temp->last_name.length();i++){
                cout<<" ";
            }
            

            cout<<temp->account_type;
            for(int i=0;i<15-temp->account_type.length();i++){
                cout<<" ";
            }
            

            cout<<temp->gender;
            for(int i=0;i<7;i++){
                cout<<" ";
            }
            

            cout<<temp->account_no;
            ostringstream str1;
            str1 << temp->account_no;
            string geek = str1.str();
            for(int i=0;i<20-geek.length();i++){
                cout<<" ";
            }
            

            cout<<temp->balance;
            ostringstream str2;
            str2 << temp->balance;
            string geek2 = str2.str();
            for(int i=0;i<15-geek2.length();i++){
                cout<<" ";
            }
            

            cout<<temp->date_created;
            for(int i=0;i<22-temp->date_created.length();i++){
                cout<<" ";
            }
            

            cout<<temp->time;
            
            
        cout<<endl;
    }

    void acc_enquiry(int a){
        cout<<endl;
        a=acc_validity(a);
        Node * temp = head; 
        int k; 
        while(temp->account_no!=a){
            temp=temp->next;
        }
        cout<<"First name          ";  //allocate 20 spaces
        cout<<"Last name           ";   //allocate 20 spaces
        cout<<"Mobile Number  "; //allocate 15 spaces
        cout<<"Gender  ";     //allocate 8 spaces
        cout<<"Account no          ";  //allocate 20 spaces
        cout<<"Balance        ";   //allocate 15 spaces
        cout<<"Date created          "; //allocate 20 spaces
        cout<<"Time created           "<<endl; //allocate 20 spaces
        cout<<"--------------------------------------------------------------------------------------------------------------------------------------------"<<endl;


            cout<<temp->first_name;
            for(int i=0;i<20-temp->first_name.length();i++){
                cout<<" ";
            }
            

            cout<<temp->last_name;
            for(int i=0;i<20-temp->last_name.length();i++){
                cout<<" ";
            }
            

            cout<<temp->account_type;
            for(int i=0;i<15-temp->account_type.length();i++){
                cout<<" ";
            }
            

            cout<<temp->gender;
            for(int i=0;i<7;i++){
                cout<<" ";
            }
            

            cout<<temp->account_no;
            ostringstream str1;
            str1 << temp->account_no;
            string geek = str1.str();
            for(int i=0;i<20-geek.length();i++){
                cout<<" ";
            }
            

            cout<<temp->balance;
            ostringstream str2;
            str2 << temp->balance;
            string geek2 = str2.str();
            for(int i=0;i<15-geek2.length();i++){
                cout<<" ";
            }
            

            cout<<temp->date_created;
            for(int i=0;i<22-temp->date_created.length();i++){
                cout<<" ";
            }
            

            cout<<temp->time;
            
            
        cout<<endl;
        main_menu_ret();
    }
    
    void Withdraw(int a){ //a is the account no..
        a=acc_validity(a);
        Node * temp = head;
        while(temp->account_no!=a){
            temp=temp->next;
        }
        show_balance_2(a);

        cout<<"Enter the amount to be withdrawn : ";
        string h; cin>>h;
        while(true){
            if(isNumber(h)){
                break;
            }
            else{
                cout<<"Reenter : ";
                cin>>h;
            }
        }
        int k=stoi(h);
        while(true){
            if(k<temp->balance-500){
               break;
            }
            else{
                 cout<<"Unable to withdraw"<<endl;
                cout<<"Please enter a valid amount : ";
                cin>>k; //k conatins the amount to be withdrwan.
            }
        }     
        temp->balance=temp->balance-k;
        string d = date_time();
        string kuc=d; 
        d = d.substr(0,10);
        kuc = kuc.substr(11,8);
        //obj[temp->id_node].insert_data_transaction(temp->account_no,d,kuc,temp->balance,"Withdraw",temp->first_name,temp->last_name);
        insert_data_transaction(temp->account_no,temp->first_name,temp->last_name,temp->balance,"Withdraw",d,kuc,temp);
        show_balance_2(a);
        main_menu_ret();
    }

    void close_acc(int a){
        a=acc_validity(a);
        Node* temp = head;
        Node* prev = NULL;
        if (temp != NULL && temp->account_no == a)
        {
            head = temp->next; // Changed head
            number_of_customers--;
            delete temp;            // free old head
            main_menu_ret();
        }
    
        else
        {
            while (temp != NULL && temp->account_no != a)
            {
                prev = temp;
                temp = temp->next;
            }
 
    
            if (temp == NULL){
                cout<<"The customers are nill.."<<endl;
                main_menu_ret();
            }
            
    
            prev->next = temp->next;
            number_of_customers--;
            delete temp;
            main_menu_ret();
        }
    }

    void deposit(int a){
        Admin app;
        a=acc_validity(a);
        Node * temp = head; 
        int k; string kid;
        while(temp->account_no!=a){
            temp=temp->next;
        }
        show_balance_2(a);
        cout<<"Enter amount : ";

        while(true){
            cin>>kid;
            while(!isNumber(kid)){
                cout<<"Enter a valid input :";
                cin>>kid;
            }
            k=stoi(kid);
            if(k>0){
                break;
            }
            else{
                cout<<"Please enter a valid amount to deposit"<<endl;
            }
        }
        temp->balance=temp->balance+k;
        string d = date_time();
        string kuc=d; 
        d = d.substr(0,10);
        kuc = kuc.substr(11,8);

        //obj[temp->id_node].insert_data_transaction(temp->account_no,d,kuc,temp->balance,"Deposit",temp->first_name,temp->last_name);
        insert_data_transaction(temp->account_no,temp->first_name,temp->last_name,temp->balance,"Withdraw",d,kuc,temp);
        cout<<"Amount has been added"<<endl;
        show_balance_2(a);
        main_menu_ret();

    }
    
    void searchByName(string a, string b){
        Node * temp = head;
        int flag=0;
        while(temp!=NULL){
            if(temp->first_name==a&&temp->last_name==b){
                acc_enquiry_1(temp->account_no);
                flag++;
            }
            temp=temp->next;
        }
        if(flag>0){
            main_menu_ret();
            return;
        }
        cout<<"This account doesn't exist in this bank"<<endl;
        
        while(true){
            Node * temp=head;
            cout<<"Please enter a valid first name :";
            string k1; cin>>k1;
            cout<<"Please enter a valid last name :";
            string k2; cin>>k2;
            while(temp!=NULL){
                if(temp->first_name==k1&&temp->last_name==k2){
                    acc_enquiry_1(temp->account_no);
                    main_menu_ret();
                    break;
                }
                temp=temp->next;
            }
            cout<<"\nThis account doesn't exist in this bank"<<endl;
            cout<<"Please enter a valid account number :";
        }
    }

    void i(){
    cout<<"\n---------------------------------------------------------------"<<endl;
    cout<<"Enter your first name : ";
    string fn; cin>>fn;
    while(true){
        if(fn.length()<=10 && isValidName(fn)){
            break;
        }
        else{
            cout<<"Invalid input "<<endl;
            cout<<"Reneter : ";
            cin>>fn;
        }
    }
    cout<<endl<<"Enter your last name : ";
    string ln; cin>>ln;
    while(true){
        if(ln.length()<=10 && isValidName(ln)){
            break;
        }
        else{
            cout<<"Invalid input "<<endl;
            cout<<"Reneter : ";
            cin>>ln;
        }
    }
    cout<<endl<<"Enter your Mobile Number : ";
    string y;
    while(true){
        cin>>y;
        if(isValid(y)){
            break;
        }
        cout<<"Not a valid mobile number ";
        cout<<"\nEnter : ";
    }
    string u;
    cout<<"\nSelect your gender M or F : ";
    while(true){
        cin>>u;
        if(u=="M"||u=="F"){
            break;
        }
        else cout<<"Enter a valid input : ";
    }
    cout<<endl<<"Enter your intial deposit amount : ";
    string appl; cin>>appl;
    while(true){
        if(isNumber(appl)){
            break;
        }
        cout<<"Not a valid amount"<<endl;
        cout<<"Renter : ";
        cin>>appl;
    }
    int am = stoi(appl);
    while(true){
        if(am>500){
            break;
        }
        cout<<"Minimun 500 deposit is required "<<endl;
        cout<<"Enter : "; cin>>am;
    }
    cout<<endl<<"Enter your password : ";
    string p; cin>>p;
    cout<<endl;
    printStrongNess(p);
    cout<<endl;
    int acc; acc=id+1;
    cout<<"\n---------------------------------------------------------------"<<endl;
    cout<<"YOUR ACCOUNT HAS BEEN CREATED  ....\n"<<endl;
    cout<<endl<<"Your Account number is : "<<acc<<endl;
    string d = date_time();
    string k=d; 
    d = d.substr(0,10);
    k = k.substr(11,8);
    insert_user(fn,ln,y,u,acc,am,p,d,k);
    main_menu_ret();
    }
    
    void update_details(int a){
        a = acc_validity(a);

        cout<<"\n";
        cout<<"Press 1 to change the first name "<<endl;
        cout<<"Press 2 to change the last name "<<endl;
        cout<<"Press 3 to change the Mobile number "<<endl;
        cout<<"Press 4 to change the password "<<endl;
        Node * temp=head;
        while(temp!=NULL){
            if(temp->account_no==a){
                break;
            }
            temp=temp->next;
        }
        while(true){
            cout<<"Enter : ";
            string k; cin>>k;
            if(k=="1"){
                string kui; 
                cout<<"Enter the name you want to change : ";
                cin>>kui;
                while(true){
                    if(kui.length()<=10 && isValidName(kui)){
                        break;
                    }
                    else{
                        cout<<"Invalid input "<<endl;
                        cout<<"Reneter : ";
                        cin>>kui;
                    }
                }
                temp->first_name=kui;
                break;
            }
            else if(k=="2"){
                string kui; 
                cout<<"Enter the name you want to change : ";
                cin>>kui;
                while(true){
                    if(kui.length()<=10 && isValidName(kui)){
                        break;
                    }
                    else{
                        cout<<"Invalid input "<<endl;
                        cout<<"Reneter : ";
                        cin>>kui;
                    }
                }
                temp->last_name=kui;
                break;
            }
            else if(k=="3"){
                string j;
                cout<<"Enter your new mobile number : ";
                while(true){
                    cin>>j;
                    if(isValid(j)){
                        break;
                    }
                    cout<<"Not a valid mobile number ";
                    cout<<"\nEnter : ";
                }
                temp->account_type=j;
                break;
            }
            else if(k=="4"){
            string k; 
            cout<<"Enter your old password : ";
            while(true){
                cin>>k;
                if(temp->password==k){
                    break;
                }
                cout<<"Incorrect password"<<endl;
                cout<<"Enter : ";
            }
            cout<<"Enter your new password : ";
            cin>>k;
            temp->password=k;
            break;
            }
            else{
                cout<<"Enter a valid input"<<endl;
            }
        }
        main_menu_ret();
    }

    void ATM_withdraw(){
        int k;
        cout<<"To user login "<<endl;
        cout<<"Enter your Account Number :";
        int flag=0;
        Node * temp1=head;
        while(true){
            Node * temp= head;
            string ido; cin>>ido;
            while(!isNumber(ido)){
                cout<<"Enter a valid input :";
                cin>>ido;
            }
            int acc = stoi(ido);
            cout<<endl;
            while(temp!=NULL){
                if(temp->account_no==acc){
                    temp1=temp;
                    flag=1;
                    break;
                }
                else{
                    temp=temp->next;
                } 
            }
            if(flag==0){
                cout<<"Reenter your Account Number : ";
            }
            else{
                break;
            }
        }
        while(true){
            cout<<"Enter your password : ";
            string p; cin>>p;
            if(temp1->password==p){
                cout<<"\n\nWELCOME "<<endl;
                cout<<"Enter the amount to be withdrawn : ";
                while(true){
                    cin>>k; //k conatins the amount to be withdrwan.
                    if(k>temp1->balance-500 || k<0){
                        cout<<"Unable to withdraw"<<endl;
                        cout<<"Please enter a valid amount : ";
                    }
                    else{
                        break;
                    }
                }
                break;
            }
        }
     
        temp1->balance=temp1->balance-k;
        string d = date_time();
        string kuc=d; 
        d = d.substr(0,10);
        kuc = kuc.substr(11,8);
        //obj[temp1->id_node].insert_data_transaction(temp1->account_no,d,kuc,temp1->balance,"ATM",temp1->first_name,temp1->last_name);
        insert_data_transaction(temp1->account_no,temp1->first_name,temp1->last_name,temp1->balance,"ATM",d,kuc,temp1);
        show_balance_2(temp1->account_no);
        main_menu_ret();
        return;
    }

    void Main_menu(){
        cout<<"MAIN MENU"<<endl;
        cout<<"-----------------------------------------------------------------------------------"<<endl;
        cout<<"\n            Press 1 to Add a customer "<<endl;
        cout<<"            Press 2 to Withdraw money "<<endl;
        cout<<"            Press 3 to Deposit money "<<endl;
        cout<<"            Press 4 to Account enquiry "<<endl;
        cout<<"            Press 5 to Close Customer "<<endl;
        cout<<"            Press 6 to Show Balance "<<endl;
        cout<<"            Press 7 to View the List of all the current customers "<<endl;
        cout<<"            Press 8 to Update the details of customer "<<endl;
        cout<<"            Press 10 to Search the customer by name "<<endl;
        cout<<"            Press 11 to view the customers according to their descending balance"<<endl;
        cout<<"            Press 12 to view the last n transactions "<<endl;
        cout<<"            Press 13 to visit ATM "<<endl;
        cout<<"            Press 14 to exit \n"<<endl;
        cout<<"-----------------------------------------------------------------------------------"<<endl;
        cout<<"Enter : ";
        string key; cin>>key;
        
        while(true){
            
        cout<<endl;
        if(key=="1"){
            cout<<"Please fill the details\n"<<endl;
            i();
            break;
        }
        else if(key=="2"){
            cout<<"Enter the account number : ";
            int a; cin>>a;
            Withdraw(a);
            break;
        }
        else if(key=="3"){
            cout<<"Enter the account number : ";
            int a; cin>>a;
            deposit(a);
            break;
        }
        else if(key=="4"){
            cout<<"Enter the account number : ";
            int a; cin>>a;
            acc_enquiry(a);
            break;
        }
        else if(key=="5"){
            cout<<"Enter the account number : ";
            int a; cin>>a;
            close_acc(a);
            break;
        }
        else if(key=="6"){
            cout<<"Enter the account number : ";
            int a; cin>>a;
            show_balance(a);
            main_menu_ret();
            break;
        }
        else if(key=="7"){
            display();
            break;
        }
        else if(key=="8"){
            cout<<"Enter the account number : ";
            int a; cin>>a;
            update_details(a);
            break;
        }
        else if(key=="10"){
            cout<<"Enter your first name :";
            string a; cin>>a;
            cout<<"Enter your last name :";
            string b; cin>>b;
            searchByName(a,b);
            break;
        }
        else if(key=="11"){
            insert_into_bst();
            main_menu_ret();
            break;
        }
        else if(key=="12"){
            cout<<"Enter the account number : ";
            int ijh; cin>>ijh;
            ijh=acc_validity(ijh);
            Node * temp = head;
            while(temp->account_no!=ijh){
                temp=temp->next;
            }
            display_n_transactions(temp);
            main_menu_ret();
            break;
        }
        else if(key=="13"){
            ATM_withdraw();
            break;
        }
        else if(key=="14"){
            cout<<"Logging out"<<endl;
            cout<<"Please wait"<<endl;
            save();
            int n =7;
            while(n!=0){
                cout<<".";
                timer(1);
                cout<<"  ";
                n--;
            }
            break;
        }
        else{
            cout<<"Reenter : ";
            cin>>key;
        }
        }
    }
     
    void reader(){   
    cout<<"Im reader"<<endl;
    ifstream input("in.txt");
    string firstName, lastName, number, gender, password, dateCreated, time;
    int numberOfAccounts, accountNo, balance, numberofTransactions;
    int id_read;
    int traccountNumber; // account number..
    string trdate;       // date of transaction
    string trtime;       // time of
    int trbalance;       // balance
    string trmode;       // deposit or withdraw
    string trfirstName;  // first name
    string trlastName;   // last name
    input >> numberOfAccounts;
    input>>id_read;
    
    if (numberOfAccounts>0)
    {
        for(int i=0;i<numberOfAccounts;i++)
        {
            input >> firstName;
            input >> lastName;
            input >> number;
            input >> gender;
            input >> accountNo;
            input >> balance;
            input >> password;
            input >> dateCreated;
            input >> time;
            
            insert_user(firstName ,lastName , number,gender , accountNo ,balance,password,dateCreated,time);
            input>>numberofTransactions;
            
            for(int i=0;i<numberofTransactions;i++){
                input>>traccountNumber;
                input>>trfirstName;
                input>>trlastName;
                input>>trbalance;
                input>>trmode;
                input>>trdate;
                input>>trtime;
                insert_data_transaction(traccountNumber,trfirstName,trlastName,trbalance,trmode,trdate,trtime,head);
                
            }     
        }
        id=id_read;
        cout<<"\nPrevious data restored ....\n\n";
    }

}

    void save(){
        ofstream output("in.txt");
        Node * temp = head;
        if (output.is_open()){
            output<<number_of_customers;
        output<<"\n";
            output<<id;
            output<<"\n";
        while(temp!=NULL){
            output<<temp->first_name<<" ";
            output<<temp->last_name<<" ";
            output<<temp->account_type<<" ";
            output<<temp->gender<<" ";
            output<<temp->account_no<<" ";
            output<<temp->balance<<" ";
            output<<temp->password<<" ";
            output<<temp->date_created<<" ";
            output<<temp->time;
            output<<"\n";
            output<<temp->number_of_transactions;
            output<<"\n";
            Node2 * temp2=temp->head2;
            while(temp2!=NULL){
                output<<temp2->acc2<<" ";
                output<<temp2->n2<<" ";
                output<<temp2->l2<<" ";
                output<<temp2->b2<<" ";
                output<<temp2->mode<<" ";
                output<<temp2->d2<<" ";
                output<<temp2->t2;
                output<<"\n";
                temp2=temp2->next2;
            }
            temp=temp->next;
        }
        }
        else{
            cout << "Problem with opening file";
        }
        return;
        
    }

};

void admin_login(){

    int user_id=8679; int password=233456;
    cout<<"Enter your user id : ";
    while(true){
        string ido; cin>>ido;
        while(!isNumber(ido)){
            cout<<"Enter a valid input :";
            cin>>ido;
        }
        int id = stoi(ido);
        cout<<endl;
        if(user_id==id){
            cout<<"Enter your Password : ";
            break;
        }
        else{
            cout<<"No such id exists.."<<endl;
            cout<<"Renter your id : ";
        }
    }
    int count=0;
    while(true){
        string passo; cin>>passo;
        while(!isNumber(passo)){
            cout<<"Enter a valid input :";
            cin>>passo;
        }
        int pass;
        pass = stoi(passo);
        cout<<endl;
        if(password==pass){
            cout<<"Welcome Mr.DSA\n";
            while(true){
                cout<<"Press 1 to enter the Main menu"<<endl;
                cout<<"Press 2 to exit"<<endl;
                cout<<"Enter : ";
                int tu;
                cin>>tu;
                if(tu==1){
                    Admin app;
                    app.reader();
                    app.Main_menu();
                    return;
                }
                else if(tu==2){
                    cout<<"You are logging out"<<endl;
                    return;
                }
                else{
                    cout<<"Please enter a valid input"<<endl;
                }
            }
            break;
        }
        else{
            cout<<"Incorrect password"<<endl;
        }
        count++;
        if(count==2){
            cout<<"You are left with one more chance to login"<<endl;
        }
        if(count==3){
            cout<<"You have reached the limit by entering the wrong password 3 times.."<<endl;
            cout << "Wait 10 seconds " << endl;
            timer(10);
        }
        cout<<"Renter your password : ";
    }
}

//Note admin is DSA : user id : 8679 , password : 233456

int main(){
    pattern();
    admin_login();
}
