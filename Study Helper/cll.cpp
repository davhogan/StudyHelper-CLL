//By David Hogan
//Email:davhogan@pdx.edu
//Student ID: 989671828

#include "cll.h"
using namespace std;

//c_node class

//Constructors
//Default Constructor
c_node::c_node():mat(NULL),next(NULL)
{}

//Constructor for a list of study questions.
//Takes in the name and category for the questions.
c_node::c_node(char * a_name,char * a_category)
{
  mat = new questions(a_name,a_category);
  next=NULL;
}

//Constructor for when the study material is a book or a set of slides.
//Takes in the type of study material 'B' for text book 'S' for slides.
//It also takes in the name of the class,the associated category and the title or location depending on which type of study material it is. 
c_node::c_node(char type, char* a_name, char* a_category, char* a_title_or_loc)
{
  if(type=='S')
    mat = new slides(a_name,a_category,a_title_or_loc);
  else 
    mat = new book(a_name,a_category,a_title_or_loc);
  
  next=NULL;
}

//Destructor
c_node::~c_node()
{
  delete mat;
  mat=NULL;
  
  delete next;
  next=NULL;
}   

//Adds a question to the list of questions.
//Takes in a question to add, makes sure that the study material is a list of questions.
//Then it inserts the question to the front of the list.
bool c_node::addQuestion(char* &question)
{
  int q_num=0;
  l_node* head=NULL;
  //Not a list of questions.
  if(!cmpType('Q'))
     return false;
  
  dynamic_cast<questions*>(mat)->getNumQ(q_num);//Get the number of questions.
  l_node* to_add = new l_node(question,q_num+1);//Create a new l_node sending in the question and the question's number.

  dynamic_cast<questions*>(mat)->getHead(head);//Get the head of the LLL.
  dynamic_cast<questions*>(mat)->insert(head,to_add);//Add the question to the front of the LLL.

  return true;
}

//Removes a question from the list of questions.
//Takes in the number of the question to remove, makes sure that the study material is a list of questions.
//Then it goes through and removes the desired question from the LLL.
bool c_node::removeQuestion(int to_remove)
{
  int q_num=0;
  l_node* head=NULL;
  
  //Not a list of questions 
  if(!cmpType('Q'))
     return false;

  dynamic_cast<questions*>(mat)->getHead(head);
  dynamic_cast<questions*>(mat)->remove(head,to_remove);

  return true;

}

//Simple function to compare the study material's type to a given type.
//Calls the material classes compare category function.
//Returns true if the types match otherwise it returns false.
bool c_node::cmpType(char a_type)
{
   if(mat->cmpType(a_type))
     return true;
   else
     return false;
}

//Simple function to compare the study material's name to a given name.
//Calls the material classes compare name function.
//Returns true if the names match otherwise it returns false.
bool c_node::cmpName(char* a_name)
{
   if(mat->cmpName(a_name))
     return true;
   else
     return false;
}

//Function to compare the study material's category to a given category.
//Calls the material classes compare category function.
//Returns true if the categories match otherwise it returns false.
bool c_node::cmpCategory(char* a_category)
{
   if(mat->cmpCategory(a_category))
     return true;
   else
     return false;
}

//Display the study material's information. 
//Calls the material class's display function.
//Returns false if there is no study material to display.
//Else it returns true
bool c_node::display()
{
  if(mat==NULL)
    return false;

  mat->display();
  return true;
}

bool c_node::displayQuestions()
{  
   //The study material isn't a list of questions
   if(!mat->cmpType('Q'))
     return false;
   
   l_node* head=NULL;
   dynamic_cast<questions*>(mat)->getHead(head);
   dynamic_cast<questions*>(mat)->displayList(head);
}
//Utlity Functions

//Getter function for the c_node's next pointer
//Takes in a c_node by reference that will copy the next pointer
//Returns false if the next pointer is NULL
//Else it returns true
bool c_node::getNext(c_node* &a_copy)
{
 // if(next==NULL)
   // return false;

  a_copy=next;
  return true;
}

//Setter function to set the c_node's next pointer
//Takes in a constant c_node to be the new destnation of next
//Returns false if the destination is NULL
//Else it returns true
bool c_node::setNext(c_node* &a_dest)
{
   if(a_dest==NULL)
    return false;

   next=a_dest;
   return true;
}

//c_list class

//Constructors

c_list::c_list():rear(NULL)
{}

//Destructor
c_list::~c_list()
{
  delete rear;
  rear=NULL;
}

//This function is used to insert a piece of study material into the CLL
//The function expects the head of the CLL to be passed in to start.
//The function then inserts the new piece of study material to the front of the list
bool c_list::insert(c_node* &curr, c_node* &to_add)
{
   c_node* next=NULL;//used to get the next node in the list for the recurssive call
  
  //Nothing to add
  if(to_add==NULL)
    return false; 
  
  //List is empty
   if(rear==NULL)
   {
      rear=to_add;
      rear->setNext(rear);
      to_add->setNext(rear);
     return true;
   }

   rear->getNext(next);//Get the head of the list
   //Insert at the front of the list. Because the current passed in is the head and rear->next is the head of the list 
   if(curr==next)
   {
      rear->setNext(to_add);//set rears next to point to the head of the list
      to_add->setNext(next);//link up the node to add to the CLL
      return true;
   }

   curr->getNext(next);//Get the next node for the recursive step
   insert(next,to_add);//recursive step
 
   return false;
}

//This function removes a given node from the CLL.
//The function expects to have the head of the list passed in and the node to remove.
//The function goes through the list until it finds the node to remove.
//The node is then removed and deleted and the rest of the CLL is linked back up. 
bool c_list::remove(c_node* &curr, c_node* &to_remove)
{
   c_node* c_next=NULL;//curr->next
   c_node* c_next2=NULL;//curr->next->next
   c_node* r_next=NULL;//rear->next
   c_node* r_next2=NULL;//rear->next->next
 //Nothing to Remove
   if(to_remove==NULL)
     return false;
   
   //List is empty nothing to remove
   if(rear==NULL)
    return false;

   rear->getNext(r_next);
   r_next->getNext(r_next2);

   curr->getNext(c_next);//Get curr's next 
   
   //1 item in list
   if(r_next==rear)
   {
     c_node* temp=NULL;
     rear->setNext(temp);
     //delete rear;
     rear=NULL;
     return true;
  }

   //The next item in the CLL is the node to remove
   if(c_next==to_remove)
   {
   //  rear->getNext(r_next);//Get rear's next
     //Removing from the front
     if(c_next==r_next)
     {
       //delete to_remove;
       curr->setNext(c_next2);
      // rear->setNext();
       r_next=NULL;
       return true;
     }
     //Removing from the end
     else if(c_next==rear)
     {
       c_next->getNext(c_next2);
       //delete to_remove;
      // c_next=NULL;
       bool check = curr->setNext(c_next2);
       rear=curr;
       return true;  
     }
     //Removing in the middle
     else
     {
       c_next->getNext(c_next2);
       //delete to_remove;
       c_next=NULL;
       
       curr->setNext(c_next2);
       c_next=NULL; 
       return true;
     } 
   }  
   //Recursive Call
   remove(c_next,to_remove);

  return false;
}

//This function takes in the head of the CLL, the category to add to and a question to add.
//It goes through the CLL checking if the given category matches the material's category and the material is a list of questions.
//Then it adds the question to the LLL of question.
bool c_list::addQuestion(c_node* &curr, char* a_category, char* a_question)
{
   bool check_cat=false;
   bool check_q=false;

   c_node* c_next=NULL;

   //CLL is empty
   if(rear==NULL)
    return false;
      
   if(curr==NULL)
    return false;

   curr->getNext(c_next);
   check_cat = curr->cmpCategory(a_category);
   check_q = curr->cmpType('Q');

   //Base case reached the end of the list last node is a matching list of questions by the given category.
   if(c_next==NULL && !check_cat && !check_q)
     return false;
   else if(check_cat && check_q) 
   {
     curr->addQuestion(a_question);
     return true;
   } 
   
   addQuestion(c_next,a_category,a_question);
   return false;
}

//This function takes in the head of the CLL, the category to add to and the number of the question to remove.
//It goes through the CLL checking if the given category matches the material's category and the material is a list of questions.
//Then it removes the question from the LLL of question.
bool c_list::removeQuestion(c_node* &curr, char* a_category, int to_remove)
{
   bool check_cat=false;
   bool check_q=false;

   c_node* c_next=NULL;

   //CLL is empty
   if(rear==NULL)
    return false;
      
   if(curr==NULL)
    return false;

   curr->getNext(c_next);
   check_cat = curr->cmpCategory(a_category);
   check_q = curr->cmpType('Q');

   //Base case reached the end of the list last node is a matching list of questions by the given category.
   if(c_next==NULL && !check_cat && !check_q)
     return false;
   else if(check_cat && check_q) 
   {
     curr->removeQuestion(to_remove);
     return true;
   } 
   
   removeQuestion(c_next,a_category,to_remove);
   return false;
}


//Display the entire CLL
//Recursively goes through and displays the entire CLL by calling the material display function. Which is a virtual function so the proper type of study material wil call its own display function
//The function expects to take in the head of the list by having rear->next be passed into it at the start.
//The function then goes through the list until it reaches the rear of the CLL.
bool c_list::displayList(c_node* &curr)const
{
   if(curr==NULL)
     return false;

   else if(curr==rear)
   {
     curr->display();//display the last material in the list
     return true;

   }
   //Display the current material
   curr->display();
   //Getting the next node in the list 
   c_node * temp=NULL;
   curr->getNext(temp);
   //Recursive step;
   displayList(temp);

  return true;
}

//Display all book in the entire CLL
//Recursively goes through and check if the study material is a book, if it is the materials information is displayed.
//The function expects to take in the head of the list by having rear->next be passed into it at the start.
//The function then goes through the list until it reaches the rear of the CLL.
bool c_list::displayBooks(c_node* &curr)const
{
   if(curr==NULL)
     return false;

   else if(curr==rear)
   {
     if(curr->cmpType('B'))
        curr->display();//display the last material in the list
     return true;
   }
   
   //Display the current material
   if(curr->cmpType('B'))
     curr->display();
   //Getting the next node in the list 
   c_node * temp=NULL;
   curr->getNext(temp);
   //Recursive step;
   displayBooks(temp);

  return true;
}

//Display every location of slides in the entire CLL
//Recursively goes through and checks if the study material is a slide, if it is the material's information is displayed.
//The function expects to take in the head of the list by having rear->next be passed into it at the start.
//The function then goes through the list until it reache the rear of the CLL.
bool c_list::displaySlides(c_node* &curr)const
{
   if(curr==NULL)
     return false;

   else if(curr==rear)
   {
     if(curr->cmpType('S'))
        curr->display();//display the last material in the list

     return true;
   }
   //Display the current material
   if(curr->cmpType('S'))
     curr->display();
   //Getting the next node in the list 
   c_node * temp=NULL;
   curr->getNext(temp);
   //Recursive step;
   displaySlides(temp);

  return true;
}

//Displays every piece of study material associated with a given category in the CLL
//Recursively goes through and checks if the material matches the given category, if it does then the material's information is displayed.
//The function expects to take in the head of the list by having rear->next be passed into it at the start.
//The function then goes through the list until it reache the rear of the CLL.
bool c_list::displayByCategory(c_node* &curr, char* a_category)const
{
   if(curr==NULL)
     return false;

   else if(curr==rear)
   {
     if(curr->cmpCategory(a_category))
       curr->display();//display the last material in the list
     return true;

   }
   //Display the current material
   if(curr->cmpCategory(a_category))
     curr->display();
   //Getting the next node in the list 
   c_node * temp=NULL;
   curr->getNext(temp);
   //Recursive step;
   displayByCategory(temp,a_category);

  return true;
}

//Displays every piece of study material that has a given class name in the CLL
//Recursively goes through and checks if the material is the same as a given name then it displays the material's information if it is a match.
//The function expects to take in the head of the list by having rear->next be passed into it at the start.
//The function then goes through the list until it reache the rear of the CLL.
bool c_list::displayByClass(c_node* &curr, char* a_name)const
{
   if(curr==NULL)
     return false;

   else if(curr==rear)
   {
     if(curr->cmpName(a_name))
       curr->display();//display the last material in the list
     return true;

   }
   //Display the current material
   if(curr->cmpName(a_name))
      curr->display();
   //Getting the next node in the list 
   c_node * temp=NULL;
   curr->getNext(temp);
   //Recursive step;
   displayByClass(temp,a_name);

  return true;
}

//Displays the list of questions for a given category.
//Recursively goes through and checks if the study material is a list of questions and its category is the same as the given category. If it is then all of the questions for that category are displayed.
//The function expects to take in the head of the list by having rear->next be passed into it at the start.
//The function then goes through the list until it reache the rear of the CLL.
bool c_list::displayQuestionCategory(c_node* &curr, char* a_category)const
{
   if(curr==NULL)
     return false;

   else if(curr==rear)
   {
     if(curr->cmpType('Q') && curr->cmpCategory(a_category))
       curr->displayQuestions();//display the last material in the list
     return true;

   }
   //Display the current material
     if(curr->cmpType('Q') && curr->cmpCategory(a_category))
        curr->displayQuestions();
   //Getting the next node in the list 
   c_node * temp=NULL;
   curr->getNext(temp);
   //Recursive step;
   displayQuestionCategory(temp,a_category);

  return true;
}

bool c_list::getStart(c_node* &copy)
{
   if(rear==NULL)
     copy=rear;
   else
     rear->getNext(copy);

   return true;
}
//Gets the rear of the list.
//Takes in a c_node to copy the rear to.
bool c_list::getRear(c_node* &a_copy)
{
  a_copy=rear;
  return true;
} 

//Gets the rear's next pointer.
//Takes in a c_node to copy the rear's next pointer.
bool c_list::getRearNext(c_node* &a_copy)
{
   rear->getNext(a_copy);
   return true;
}

