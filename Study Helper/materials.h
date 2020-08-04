//By David Hogan
//Email:davhogan@pdx.edu
//Student ID: 989671828

#include <iostream>
#include <cctype>
#include <cstring>
#include <stdlib.h>
#include <math.h>

//The purpose of this file is to represent a piece of study material.
//The study material can either be a textbook to read, a set of slides to review or a list of questions to practice. Because these different materails act differently there is an abstract base class of the study materials to help represent the basics that every piece of study material has. 
//The different pieces of materials all have a type, name and category associated with it.

//The class is used to represent a node in a linear linked list.
//An l_node has a question, a number and a pointer to the next node in the LLL.
//The class can compare and update the node's number given a number.
class l_node
{
  public:
      //Constructors
      l_node();//Default.
      l_node(const l_node* &a_node);//Copy Constructor.
      l_node(char * a_question,int q_number);//Constructor given a question and a number of the question.
      //Destructor
      ~l_node();

      bool cmpNum(int to_cmp);//Compares the question's number to a given number.
      bool updateNum(int to_update);//Updates the question's number to a given number.

      bool getNext(l_node* &copy);//Gets the next pointer in the list.
      bool setNext(l_node* &dest);//Sets the next pointer in the list.
     
      bool display();//Display the question and its number. 

  protected:
      char* question;//The question.
      int  q_num;//The question's number.
      l_node * next;//The next pointer in the list.
};

//This class is the abstract base class for the different types of study materials.
//Every piece of study material has the type of material it is and the name of the class that it is for and a category to define it.
//This class doesn't do much and instead invokes the work onto it's childeren.
class material
{
   public:
         material();//Constructor
         material(const material &a_material);//Copy Constructor
         virtual ~material();//Destructor
         virtual bool display()=0;//Pure virtual function. 

         bool cmpType(char a_type);//Compare a study material's type with a given type.
         bool cmpName(char * a_name);//Compares a study material's name with a given name.
         bool cmpCategory(char * a_category);//Compares a study material's category with a given category
  
   protected:
         char type;//Indicator for which type of study material the object is
         char * c_name;//Name of the class the book is for 
         char * category;//The category for the  

};

//Child class of the abstract base class: material
//The purpose of this class is to represent a textbook that should be read
//A textbook has a title of the book
class book: public material
{
   public:
         //Constructors
         book();//Default
         book(const book &a_book);//Copy Constructor
         book(const char* a_name, const char * a_category, const char* a_title);//Constructor for a book when given a name,category and title
       
         //Destructor
         ~book();
        
         bool display();//Displays the title of the book,the name of the class the book is for and the realted category
   
   protected:
        char * title;//title of the book

}; 

//Child class of the abstract base class: material
//The purpose of this class is to represent a set of slides for a class
//A set of slides has a file location of where the slides are kept
class slides: public material
{
   public:
         //Constructors
         slides();//Default
         slides(const slides &a_slide);//Copy Constructor
         slides(const char* a_name, const char* a_category, const char* location);//Constructor when given a name, category and location of the slides
        
        //Destructor
         ~slides();

         bool display();//Displays the location of the slides 
  
   protected:
        char* location;//File location for the slides      
};

//Child class of the abstract base class: material
//The purpose of this class is to represent a set of questions to practice for a class
//The questions has a the head and tail pointer of a linear linked list of questions and knows how many questions are in the LLL.
//This class does all the work on the LLL of questions, this includes inserting at the front, removing a given node and displaying questions in the list.
class questions: public material
{
   public:
         //Constructors
         questions();//Default
         questions(const questions &a_question);//Copy constructor.
         questions(const char* a_name, const char* a_category);//Constructor given a name and a category
        
         //Destructor
         ~questions();

         bool insert(l_node* &curr, l_node* &to_add);//Adds a question to the front of the list
         bool remove(l_node* &curr, int to_remove);//Removes the given question from the list. 
         bool display();//Displays the class,category and number of questions. 
         bool displayList(l_node* &curr);//Displays all of the questions for a given category.
         bool getNumQ(int &copy);//Get the number of questions in the LLL.
         bool getHead(l_node* &copy);//Get the head of the LLL.
    protected:
 
        int num_q;//The number of questions in the list.
        l_node* head;//The head of the LLL of questions.
        l_node* tail;//The tail of the LLL of questions.

};
