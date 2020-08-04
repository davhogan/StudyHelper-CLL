//By David Hogan
//Email:davhogan@pdx.edu
//Student ID: 989671828

//The purpose of this program is to represent a group of study materials to review.
//There are three different types of study material; a text book to read, a set of slides to review and a list of questions to practice.
//All pieces of study material have a type, the name of the class, and  a category they are associated with.
//Yet different study materials have other pieces of data unique to itself.
//The textbook has a title of the book. The slides have a file location of where the slides are located.
//The list of questions has head and tail pointer for the list of questiions as well as knowing how many questions are in the list.
//The list of questions are represented using a linear linked list.
//To keep all of the study materials together a circluar linked list of study materials is used.
//The CLL can add more study materials, remove study materials and display the study material's based on a given condition, such as their name or type. 


#include "cll.h"
using namespace std;
//Checks the user's response to make sure it is in range of the available options.
//Continues to make the user get enter a number until the one entered is in range.
//Takes in the user's response and returns the response that is in range.
int checkResponse(int user_resp)
{
  while(user_resp < 1 || user_resp > 9)
  { 
     cout<<"That isn't an acceptable command"<<endl;
     cout<<"[1] To add a study material to the list."<<endl;
     cout<<"[2] To add a question to a category."<<endl;
     cout<<"[3] To remove a question from a category."<<endl; 
     cout<<"[4] To display all study materials."<<endl;
     cout<<"[5] To display all books in the list."<<endl;
     cout<<"[6] To display all slide locations in the list."<<endl;
     cout<<"[7] To display all information for a class."<<endl;
     cout<<"[8] To display all information for a category."<<endl;
     cout<<"[9] To display questions for a given category"<<endl;      

      cin>>user_resp;
      cin.ignore(100,'\n');
   }
  
  return user_resp;
}

//Checks the user's response to make sure it is in range of the available options.
//Continues to make the user get enter a number until the one entered is in range.
//Takes in the user's response and returns the response that is in range.
int checkType(int user_resp)
{
   while(user_resp < 1 || user_resp > 3)
   {
     cout<<"Select which type of study material to add."<<endl;
     cout<<"[1] A new book."<<endl;
     cout<<"[2] A new location of slides."<<endl;
     cout<<"[3] A new set of questions."<<endl;

     cin>>user_resp;
     cin.ignore(100,'\n');
   }

  return user_resp;
}

//This is where the user interacts with the program.
//Main prompts the user to fill and interact with the CLL of study materials.
int main()
{
  int user_resp=0;//The user's response
  char cont='y';//Whether or not the user wants to continue
  char* a_category = new char[140];//The category the user enters
  char* a_name = new char[140];//The name of the class the user enters
  char* a_title = new char[140];//The title of the book the user enters
  char* a_location = new char[140];//The location of the slides the user enters
  char* a_question = new char[140];//A question the user enters
  c_node * start= NULL;//Start of the CLL

  c_list list_obj;//CLL object

   //While the user wants to continue interacting with the CLL of study materials
   while(cont=='y' || cont=='Y')
   {

      cout<<"[1] To add a study material to the list."<<endl;
      cout<<"[2] To add a question to a category."<<endl;
      cout<<"[3] To remove a question from a category."<<endl;
      cout<<"[4] To display all study materials."<<endl;
      cout<<"[5] To display all books in the list."<<endl;
      cout<<"[6] To display all slide locations in the list."<<endl;
      cout<<"[7] To display all information for a class."<<endl;
      cout<<"[8] To display all information for a category."<<endl;
      cout<<"[9] To display questions for a given category"<<endl;  
         
      cin>>user_resp;
      cin.ignore(100,'\n');

      user_resp=checkResponse(user_resp);//check in range
      //Add a new study material
      if(user_resp==1)
      {
        cout<<"Select which type of study material to add."<<endl;
        cout<<"[1] A new book."<<endl;
        cout<<"[2] A new location of slides."<<endl;
        cout<<"[3] A new set of questions."<<endl;

        cin>>user_resp;
        cin.ignore(100,'\n');

        user_resp=checkType(user_resp);//check in range
   
        cout<<"Enter the name of the class the material is for."<<endl;
        cin.getline(a_name,140); 
        cin.ignore(100,'\n');

        cout<<"Enter a category associated with the material."<<endl;
        cin.getline(a_category,140); 
        cin.ignore(100,'\n');

        //Material to add is a book
        if(user_resp==1)
        {
          cout<<"Enter a title for the book"<<endl;
          cin.getline(a_title,140); 
          cin.ignore(100,'\n');

          list_obj.getStart(start);
          c_node* set_slides = new c_node('B',a_name,a_category,a_title);
          list_obj.insert(start,set_slides);

        }
        //Material to add is a set of slides
        else if(user_resp==2)
        {
          cout<<"Enter the location of the slides"<<endl;
          cin.getline(a_location,140); 
          cin.ignore(100,'\n'); 

          list_obj.getStart(start);
          c_node* t_book = new c_node('S',a_name,a_category,a_location);
          list_obj.insert(start,t_book);

        }
        //Material to add is a list of questions.
        else if(user_resp==3)
        {
          c_node* q_list = new c_node(a_name,a_category);
          list_obj.getStart(start);
          list_obj.insert(start,q_list);

          cout<<"Would you like to add a question?(y/n)"<<endl;
          cin>>cont;
          cin.ignore(100,'\n');
          //While the user wants to add questions.
          while(cont=='y')
          {
            cout<<"What is the question to add?"<<endl;
            cin.getline(a_question,140);
            cin.ignore(100,'\n');
 
            list_obj.getStart(start);

            list_obj.addQuestion(start,a_category,a_question);             


            cout<<"Would you like to add a another question?(y/n)"<<endl;
            cin>>cont;
            cin.ignore(100,'\n');
          }
        }
      } 
      //Add a question for a certain category
      else if(user_resp==2)
      {
         cout<<"Enter the category associated with the question to add."<<endl;
         cin.getline(a_category,140); 
         cin.ignore(100,'\n');

         cout<<"What is the question to add?"<<endl;
         cin.getline(a_question,140);
         cin.ignore(100,'\n');

         list_obj.getStart(start);
         list_obj.addQuestion(start,a_category,a_question);
      }
      //Remove a question from a certain category
      else if(user_resp==3)
      {
         cout<<"Enter the category associated with the question to remove."<<endl;
         cin.getline(a_category,140); 
         cin.ignore(100,'\n');

         cout<<"What is the number of the question to remove?"<<endl;
         cin>>user_resp;
         cin.ignore(100,'\n');

         list_obj.getStart(start);
         list_obj.removeQuestion(start,a_category,user_resp);
      }
      //Display all of the study material
      else if(user_resp==4)
      {
         list_obj.getStart(start);
         list_obj.displayList(start);
      }
      //Display all of the books in the CLL
      else if(user_resp==5)
      {
         list_obj.getStart(start);
         list_obj.displayBooks(start);
      }
      //Display all of the slides locations in the CLL
      else if(user_resp==6)
      {
         list_obj.getStart(start);
         list_obj.displaySlides(start);
      }
      //Display all info for a class in the CLL
      else if(user_resp==7)
      {
         cout<<"Enter the name of the class the material is for."<<endl;
         cin.getline(a_name,140); 
         cin.ignore(100,'\n');
         
         list_obj.getStart(start);
         list_obj.displayByClass(start,a_name);
      }
      //Display all info for a category in the CLL
      else if(user_resp==8)
      {
         cout<<"Enter the category to display."<<endl;
         cin.getline(a_category,140); 
         cin.ignore(100,'\n');
         
         list_obj.getStart(start);
         list_obj.displayByCategory(start,a_category);
      }
      //Display all questions for a category in the CLL
      else if(user_resp==9)
      {
         cout<<"Enter the category associated with the questions to display."<<endl;
         cin.getline(a_category,140); 
         cin.ignore(100,'\n');
        
         list_obj.getStart(start);
         list_obj.displayQuestionCategory(start,a_category);
      }
      
       cout<<"Would you like to do anything else?(y/n): ";
       cin>>cont;
       cin.ignore(100,'\n');
  }
   
 
 return 0;
}

