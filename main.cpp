#include<iostream>
#include"LinkedList.hpp"
using namespace std;

int main(){
	LinkedList test1;
	cout<<"is it empty "<<test1.is_empty()<<endl;
	//test1.remove_first();

	try{
		//test1.remove_first();
		//test1.remove_last();
		//test1.remove_current();
		//test1.next();
		//test1.prev();
		//test1.get_first();
		//test1.get_last();
		//test1.get_current();
		test1.set_current(2);
	}
	catch(ListException &ex){
		cout<<ex.to_string()<<endl;
	}

	test1.insert_first("g");
	test1.insert_first("a");
	//test1.print_contents();
	test1.insert_first("m");
	test1.insert_first("r");
	cout<<"the size of the element is: "<<test1.get_size()<<endl;
	test1.print_contents();
	test1.insert_last("z");
	test1.print_contents();
	cout<<"the size of the element is: "<<test1.get_size()<<endl;
	cout<<"The last element is: "<<test1.get_last()<<endl;
	test1.insert_after_current("y");
	test1.print_contents();
	test1.insert_before_current("w");
	test1.print_contents();
	test1.insert_first("n");
	test1.print_contents();
	cout<<"The last element is "<<test1.get_last()<<endl;
	test1.insert_after_current("h");
	test1.print_contents();
	test1.insert_before_current("k");
	test1.print_contents();
	cout<<test1.get_first()<<endl;
	cout<<test1.prev()<<endl;
	test1.insert_after_current("o");
	test1.print_contents();
	cout<<"the size of the element is: "<<test1.get_size()<<endl;
	cout<<"the element in the current is: "<<test1.get_current()<<endl;
	test1.set_current(4);
	cout<<"the element in the current is: "<<test1.get_current()<<endl;
	test1.update_current("tr");
	cout<<"the element in the current is: "<<test1.get_current()<<endl;
	test1.print_contents();
	cout<<"the current is moved to the next: "<<test1.next()<<endl;
	test1.remove_current();
	test1.print_contents();
	test1.print_contents_reverse();
	cout<<"the size of the element is: "<<test1.get_size()<<endl;
	cout<<"the first element that was removed is: "<<test1.remove_first()<<endl;
	test1.print_contents();
	test1.print_contents_reverse();
	cout<<"the size of the element is: "<<test1.get_size()<<endl;
	cout<<"the last element that was removed is: "<<test1.remove_last()<<endl;
	cout<<"the current is moved to the prev: "<<test1.prev()<<endl;
	test1.print_contents();
	test1.print_contents_reverse();
	cout<<"the size of the element is: "<<test1.get_size()<<endl;
	cout<<"the element in the current that was removed is: "<<test1.remove_current()<<endl;
	test1.print_contents();
	test1.print_contents_reverse();
	cout<<"the size of the element is: "<<test1.get_size()<<endl;
	cout<<"the first element that was removed is "<<test1.remove_first()<<endl;
	test1.print_contents();
	test1.print_contents_reverse();
	cout<<"the size of the element is: "<<test1.get_size()<<endl;
	cout<<"the element in the current that was removed is "<<test1.remove_current()<<endl;
	test1.print_contents();
	test1.print_contents_reverse();
	cout<<"the size of the element is: "<<test1.get_size()<<endl;

	test1.remove_last();
	test1.print_contents();
	cout<<"the size of the element is: "<<test1.get_size()<<endl;
	test1.remove_current();
	cout<<"the size of the element is: "<<test1.get_size()<<endl;
	test1.print_contents();
	test1.remove_first();
	test1.print_contents();
	test1.print_contents_reverse();
	cout<<"the size of the element is: "<<test1.get_size()<<endl;
	test1.remove_current();
	cout<<"the size of the element is: "<<test1.get_size()<<endl;
	test1.print_contents();
	test1.remove_last();
	cout<<"the size of the element is: "<<test1.get_size()<<endl;
	test1.print_contents();
	test1.print_contents_reverse();
	test1.remove_current();
	
	return 0;
}
