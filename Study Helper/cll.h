//By David Hogan
//Email:davhogan@pdx.edu
//Student ID: 989671828

#include "materials.h"

//The purpose of this file is to represent a circular linked list of study materials.
//Two classes are used. One is the c_node class this represents a single node in the cll.
//The other is c_list which is used to represent and do work to a cirlaur linked list of study materials.
//A c_node has a study material pointer(which will become an object based on the type of study material).
//As well as a pointer to the next node in the cll.
//The c_list has a pointer to the rear node in the circular linked list.

//This class is used to represent a node in the circular linked list. 
//Every node has a piece of study material and a pointer to the next node in the CLL.
//The class itself doesn't do too much work basically just displaying and comparing the information of the material. The lions share of the work is given to the c_list class below.
class c_node
{
  public:
        c_node();//Constructor
        c_node(char * a_name, char * a_category);//Constructor for a list of study questions. Takes in the name of the class and the study category
        c_node(char type, char* a_name, char* a_category, char* a_title_or_loc);//Constructor for when the study material is a book or a set of slides. Taking in the type of study material it is, the name of the class, the study category and either the title of the book or the location of the slides  
        ~c_node();//destructor
         
         bool addQuestion(char* &question);//Adds a question to a list of questions 
         bool removeQuestion(int to_remove);//Removes a question from a list of questions
         bool display();//displays the information about the study material
         bool displayQuestions();//Displays a list of questions.
         bool cmpType(char a_type);//Compares the material's type to a given type.
         bool cmpName(char * a_name);//Compares the material's name to a given name.
         bool cmpCategory(char * a_category);//Compars the material's category to a given category.
  
         //Utility functions for getting and setting the next pointer 
         bool getNext(c_node* &a_copy);
         bool setNext(c_node* &a_dest);
  protected:
        material * mat;//a piece of study material
        c_node * next;//pointer to the next node in the CLL
};

//This class is used to represent and do work on a circular linked list of study materials.
//This class has a rear pointer to the last item in the CLL. 
//The c_list class also does all the inserting and removing of the list.
//It also has many differnet types of display functions to allow for searching given either the type of material to be displayed or the class/category to display material for.
class c_list
{
  public:
     c_list();//constructor
     ~c_list();//destructor;
     
      bool insert(c_node* &curr, c_node* &to_add);//Adds a new given piece of study material to the CLL at the end of the list.
      bool remove(c_node* &curr, c_node* &to_remove);//Reoves a given piece of study material from the CLL. 
      bool addQuestion(c_node* &curr, char* a_category, char* a_question);
      bool removeQuestion(c_node* &curr,char* a_category,int to_remove);//Removes a questions from the list based on the given number given the category. Expects to recieve the front of the list. 
      bool displayList(c_node* &curr)const;//Displays all of the information for the materials in the CLL.
      bool displayBooks(c_node* &curr)const;//Displays all of the textbooks in the CLL.
      bool displaySlides(c_node* &curr)const;//Displays all of the slides in the CLL.
      bool displayByCategory(c_node* &curr, char* a_category)const;//Displays all of the material of a given category.
      bool displayByClass(c_node* &curr, char* a_name)const;//Displays all the information of a given name of the class.
      bool displayQuestionCategory(c_node* &curr, char* a_category)const;//Displays the list of questions for a given category

      bool getStart(c_node* &a_copy);//Gets the start of the CLL      
      bool getRear(c_node* &a_copy);//Gets a copy of the rear pointer 
      bool getRearNext(c_node* &a_cnode);//Used to get the start of the list when rear isn't NULL 
  protected:
    c_node * rear;//The rear pointer of the CLL
};
