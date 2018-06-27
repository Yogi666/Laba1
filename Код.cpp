#include <iostream>
#include <string.h>
#include <sstream>

using std::cin;
using std::cout;
using std::string;

const int prev = -1;
const int next = 1;
const int outPageSize = 5;

class Page{
	private:
		int *pages;
		int *outPages;
		int size;
		
		void calc(int position);
	public:
		Page(int num_pages);
		string calculation(int position);
		void showPageModel(string str);
		~Page();
};

class System{
	private:
		bool repeat();
	public:
		void init();
		void input(int &size, int &page);
		string toString(int val);
};

 
int main(void){
	System *sys = new System();
	sys->init();
	
	return 0;
}

Page::Page(int num_pages){
	pages = new int[num_pages];
	outPages = new int[outPageSize];
	for(int i = 0; i < num_pages; i++){
		pages[i] = i+1;
	}
	this->size = num_pages;
}

void Page::showPageModel(string str){
	cout << str;
}

string Page::calculation(int position){
	string model;
	System *sys = new System;
	
	if(position >= size) model = "Value is out of range!!!";
	else{
		if(size > 5){
			if((size >= 7) && (position >= 3) && (position < size-3)){
				model = model + sys->toString(pages[0]) + " ... ";
		 	    for(int i = prev; i < next + 1; i++){
		 	    	model = model + " " + sys->toString(pages[position+i]);
				}
				model = model + " ... " + sys->toString(pages[size-1]);
			}
			else if(position < 3){ 						
				 for(int i = 0; i < position + 2; i++){
				 	model = model + sys->toString(pages[i]) + " ";
				 }
	 			 model = model + " ... " + sys->toString(pages[size-1]);
			}
			else if((position >= size - 3) && (position < size)){ 
		        model = model + sys->toString(pages[0]) + " ... ";
				for(int i = position - 1; i < size; i++){
					 model = model + sys->toString(pages[i]) + " ";	
				} 
			}  	
		}
		else{
			if(((size == 5) && (position < 2)) || ((size == 4) && (position == 0))){
				for(int i = 0; i < position + 2; i++){
					model = model + sys->toString(pages[i]);
					if(i < position + 1) cout << " ";
					else model = model + " ... " + sys->toString(pages[size-1]);	
				}
			}
			else if(((size == 5) && (position > size - 3)) ||((size == 4) && (position == size-1))){
				model = model + sys->toString(pages[0]) + " ... ";
				for(int i = position - 1; i < size; i++){
					model = model + sys->toString(pages[i]) + " ";
				}
			}
			else{
				for(int i = 0; i < size; i++){
					model = model + sys->toString(pages[i]) + " ";
				}
			}	
		}
	}
	
	delete sys;
	return model;
}

Page::~Page(){
	delete []pages;
}


///////////////////////////////***************************CLASS SYSTEM*************************/////////////////////////////////////////////

void System::input(int &size, int &page){
	while(size < 1){
		cout << "Enter the size of array: ";
    	cin >> size;	   	
	}
	
	while(page < 1){
		cout << "\n\nEnter the page: ";
		cin >> page;
		cout << "\n";	
	}
}

bool System::repeat(){
	cout << "\n\nDo you want to repeat: ";
	char asw = 0;
	cin >> asw;
	cout << "\n\n";
	if(asw == 'Y' || asw == 'y') return true;
	else if(asw == 'N' || asw == 'n') return false;
	else repeat();
}

void System::init(){
	int size = 0;
	int page = 0;
	input(size,page);
	
	Page *page_model = new Page(size);
	page_model->showPageModel(page_model->calculation(page-1));
	delete page_model;
	
	if (repeat() == true) init();
	else{}
}

string System::toString(int val){
	std::ostringstream oss;
	oss << val;
	return oss.str();
}
