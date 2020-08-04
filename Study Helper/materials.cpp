//By David Hogan
//Email:davhogan@pdx.edu
//Student ID: 989671828

#include "materials.h"
using namespace std;



l_node::l_node():question(NULL),q_num(0),next(NULL)
{}

//Copy Constructor to make a deep copy of an l_node
l_node::l_node(const l_node* &a_node)
{
  int len = strlen(a_node->question);
  question = new char[len+1];
  strcpy(question,a_node->question);

  q_num=a_node->q_num;
  next=a_node->next;
}

//Constructor given a question and a number for the question's number.
l_node::l_node(char * a_question, int a_number)
{
  int len = strlen(a_question);
  question = new char[len+1];
  strcpy(question,a_question);
  
  q_num=a_number;
  next=NULL;

}

l_node::~l_node()
{
  delete(question);
  question=NULL;
  
}

//Compares the question's number to a given number.
//Returns true if it is else it returns false.
bool l_node::cmpNum(int to_cmp)
{
  if(q_num==to_cmp)
   return true;  
  else
   return false;
}

//Updates the question's number to a given number.
bool l_node::updateNum(int to_update)
{
  q_num=to_update;
  return true;
}

//Gets the next pointer in the list by copying next to a passed in variable.
bool l_node::getNext(l_node* &copy)
{
    copy=next;
    return true;
}

//Sets the next pointer for an l_node.
//Sets the next pointer to a given pointer.
bool l_node::setNext(l_node* &dest)
{
   next=dest;
   return true;
}

//Displays the question and its number
bool l_node::display()
{
  cout<<"#"<<q_num<<" "<<question<<endl;
}

//Abstract Base Class: Material class

//Constructors
//Default
material::material():type('\0'),c_name(NULL),category(NULL)
{

}

//Copy Constructor to deep copy the materials type, class name and category
material::material(const material &a_material)
{
   int len =0;
   type=a_material.type;
   
   len=strlen(a_material.c_name);
   c_name=new char[len+1];
   strcpy(c_name,a_material.c_name);
   
   len=strlen(a_material.category);
   category= new char[len+1];
   strcpy(category,a_material.category);

}

//Destructors

material::~material()
{
  delete c_name;
  c_name=NULL;
  delete category;
  category=NULL;
}

//Compares the material's type to a given type.
//Returns true if it matches else it returns false.
bool material::cmpType(char a_type)
{
   if(a_type==type)
     return true;
   else
     return false;
}

//Compares the material's name to a given name.
//Returns tue of the names match else returns false.
bool material::cmpName(char * a_name)
{
   if(!strcmp(a_name,c_name))
    return true;
   else
    return false;
}

//Compares the material's category to a given category.
//Returns tue of the names match else returns false.
bool material::cmpCategory(char * a_category)
{
   if(!strcmp(a_category,category))
    return true;
   else
    return false;
}

//Child Class of material class: Book class

//Constructors
book::book():title(NULL)
{
   type='B'; 
}

//Copy constructor for a book object. Does a deep copy of the book's information
book::book(const book &a_book)
{
   type='B';
   int len =0;
   
   len=strlen(a_book.title);
   title=new char[len+1];
   strcpy(title,a_book.title);
 
}

//Constructor for a book given a name of the class, an associated category and a title of the book.
book::book(const char* a_name, const char * a_category, const char* a_title)
{
   int len =0;
   type='B';
    
   len=strlen(a_name);
   c_name=new char[len+1];
   strcpy(c_name,a_name);
     
   len=strlen(a_category);
   category= new char[len+1];
   strcpy(category,a_category);
   
   len=strlen(a_title);
   title= new char[len+1];
   strcpy(title,a_title);
   
}

//Destructor
book::~book()
{
   delete title;
   title=NULL;
}

//Displays the information of a textbook.
bool book::display()
{
   cout<<"Category: "<<category<<endl;
   cout<<"Class Name: "<<c_name<<endl;
   cout<<"Book to review: "<<title<<endl<<endl;
   
   return true;
}


//Child Class of material class: slides class

//Constructors
slides::slides():location(NULL)
{
  type='S';
}

//Copy Constructor for slides.
//Does a deep copy of the slide.
slides::slides(const slides &a_slide)
{
   type='S';
   int len =0;
   
   len=strlen(a_slide.location);
   location=new char[len+1];
   strcpy(location,a_slide.location);
 
}

//Constructor for a set of slides given a name of the class, an associated category and a file location for the slides.
slides::slides(const char* a_name, const char * a_category, const char* a_location)
{
   int len =0;
   type='S';
    
   len=strlen(a_name);
   c_name=new char[len+1];
   strcpy(c_name,a_name);
     
   len=strlen(a_category);
   category= new char[len+1];
   strcpy(category,a_category);
   
   len=strlen(a_location);
   location= new char[len+1];
   strcpy(location,a_location);
   
}

//Destructor
slides::~slides()
{
   delete location;
   location=NULL;
}

bool slides::display()
{
   cout<<"Category: "<<category<<endl;
   cout<<"Class Name: "<<c_name<<endl;
   cout<<"Location of the slides: "<<location<<endl<<endl;
   
   return true;
}

//Child Class of material class: questions class

//Constructors
questions::questions():num_q(0),head(NULL),tail(NULL)
{
  type='Q';
}

//Copy Constructor for questions.
//Does a deep copy of the questions.
questions::questions(const questions &a_question)
{
   type='Q';
   num_q=a_question.num_q;
  
   head=a_question.head;
   tail=a_question.tail;

}

//Constructor for a list of questions given a name of the class, an associated category for the questions.
questions::questions(const char* a_name, const char * a_category)
{
   int len =0;
   
   type='Q';
   num_q=0;
    
   len=strlen(a_name);
   c_name=new char[len+1];
   strcpy(c_name,a_name);
     
   len=strlen(a_category);
   category= new char[len+1];
   strcpy(category,a_category);
  
   head=NULL;
   tail=NULL; 
}

//Destructor
questions::~questions()
{
  //Call function to clear out list
  for(int i=1;i<num_q+1;++i)
  {
    remove(head,i);
  } 

  head=NULL;
  tail=NULL;
  
}

//Inserts a question into the front of the list.
//Takes in a question to add then adds it to the front of the list.
bool questions::insert(l_node* &curr, l_node* &to_add)
{     
    l_node * next=curr;

    //Nothing to add
    if(to_add==NULL)
       return false;
    //Nothing in the list.
    if(head==NULL)
    {
       head=to_add;
       tail=to_add;
       ++num_q;
       return true;
    }       
    //Add to the front of the list.
    else
    {
      to_add->setNext(head);//Put the node to add at the front.
      head=to_add;//Set head to new destination.
      ++num_q;//Increment the amount of questions in the list.
      return true;
    }
   curr->getNext(next);//get the next node in the list.
   insert(next,to_add);//Recursive step.
}

//Remove a question from the LLL.
//Recursively goes through and finds the question with the give number.
//It then removes that question from the LLL.
bool questions::remove(l_node* &curr, int to_remove)
{  
   l_node* h_next = NULL;
   l_node* c_next = NULL;
   l_node* c_next2 = NULL;
   //Nothing to remove
   if(head==NULL)
     return false;

   //Only 1 item in the list to remove
   if(h_next==tail)
   {
     delete head;
     head=NULL;
     tail=NULL;
     num_q=0;
     return true;
   }

   //Make sure not to  dereference a NULL pointer.
   if(curr==NULL)
   {
    return false;
   }
   
   curr->getNext(c_next);
   
   //Question to remove is at the front
   if(head->cmpNum(to_remove) && curr==head)
   {
     head=c_next;
     delete curr; 
     curr=NULL;
     --num_q;
     return true;
   }
   //Question to remove is at the end
   else if(c_next==tail && tail->cmpNum(to_remove))
   {
     delete c_next;
     c_next=NULL;
     tail=curr;
     --num_q;
     return true;

   }
   //Question is in the middle of the list 
   else if(c_next->cmpNum(to_remove))
   {
      c_next->getNext(c_next2);
      curr->setNext(c_next2);
      delete c_next;
      c_next=NULL;
      --num_q;
      return true;
   }

   remove(c_next,to_remove);
   return false;
}
//Displays the information of questions.
//Doesn't display the list of question though.
bool questions::display()
{
   cout<<"Category: "<<category<<endl;
   cout<<"Class Name: "<<c_name<<endl;
   cout<<"Number of questions to avaliable to review: "<<num_q<<endl<<endl;
   
   return true;
}

//Displays the entire list of the questions.
//Recurisvely goes through the list and displays the question.
bool questions::displayList(l_node* &curr)
{
   l_node * next = NULL;
   //Empty List
   if(head==NULL)
    return false;
   //Base Case at the end of the list
   if(curr==tail)
   {
     curr->display();
     return true;
   }
   curr->getNext(next);
   displayList(next);
   curr->display();
}

//Gets the number of questions in the LLL
bool questions::getNumQ(int &copy)
{
  copy=num_q;
  return true;
}

//Gets the head of the LLL
bool questions::getHead(l_node* &copy)
{
   copy=head;
   return true;
}
