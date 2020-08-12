/*
 *This is a program that deals with lists of strings that allows
 *for user flexibility using double linked list.
 *Course : CSCI161.
 *Author : Khalid.
 *Date : 27/02/2020.
*/

#include<iostream>
#include"LinkedList.hpp"
using namespace std;
//creates an empty list and there is no cursor available.
LinkedList :: LinkedList(){
	first = current = last = nullptr;
	m_size = 0;
}
//Removes all the element from the list and destroys the list,
//freeing up any memeory that was allocated.
LinkedList :: ~LinkedList(){
	while(!is_empty()){
		remove_first();
	}
}
//getting the first element in the list or if the list is empty, an exception is thrown.
string LinkedList :: get_first(){
	if(first != nullptr){
		current = first;
		return first->element;
		
	}
	else{
		throw ListException("get_first()", "list is empty");
	}
}
//getting the last element in the list or if the list is empty, an exception is thrown.
string LinkedList :: get_last(){
	if(last != nullptr){
		current = last;
		return last->element;
		
	}
	else{
		throw ListException("get_last()", "list is empty");
	}
}
//getting the element at the current or if the list is empty, an exception is thrown.
string LinkedList ::  get_current() const{
	if(current != nullptr){
		return current->element;
	}
	else{
		throw ListException("get_current()", "list is empty");
	}
}
//setting the current to the index position given.
void LinkedList :: set_current(int index){
	if(!is_empty() && index < get_size() && index >= 0 ){
		current = first;
		for(int i = 0; i < index; i++){
			current = current->next;
		}
	}
	else if(index > get_size() || index < 0 || is_empty()){
		throw ListException("set_current()", "list is empty");
	}
	else{
		//nothing hapens
	}	
}
//getting the number of elements in the list.
int LinkedList :: get_size() const{
	return m_size;
}
//checking to make sure the list is not empty.
bool LinkedList :: is_empty() const{
	if(get_size() == 0){
		return true;
	}
	else{
		return false;
	}
}
//Sets the cursor to the next element to the right of the current position of the cursor. 
//If the cursor is already at the last element, then it does not move.
string LinkedList :: next(){
	if(current != nullptr){
		if(current != last){
			current = current->next;
			return current->element;
		}
	}
	else{
		throw ListException("next()", "next() is empty");
	}
	return "";
}
//Sets the cursor to the previous element to the left of the current position of the cursor. 
//If the cursor is already at the first element, then it does not move.
string LinkedList :: prev(){
	if(current != nullptr){
		if(current != first){
			current = current->prev;
			return current->element;
		}
	}
	else{
		throw ListException("prev()", "prev() is empty");
	}
	
	return "";
}
	/******************  Inserting **********************/
//insert the element in the first position.
void LinkedList :: insert_first(string element){
	first = new Node(element, first, nullptr);
	if(is_empty()){
	 	current = last = first;
	}
	else{
		first -> next -> prev = first;
		current = first;
	}
	m_size++;
}
//inserting the element in the last position.
void LinkedList :: insert_last(string element){
	last = new Node(element, nullptr, last);
	if(is_empty()){
		first = current = last;
	}
	else{
		Node *pam = last -> prev;
		pam -> next = last;
		current = last;
	}
	m_size++;
}
//inserting the element after the current position.
void LinkedList :: insert_after_current(string element){
	if(is_empty() || current == last){
		insert_last(element);
	}
	else{
		current = new Node(element, current->next, current);
		current->prev->next = current;
		current->next->prev = current;
		m_size++;
	}
	
}
//inserting the element before the current position.
void LinkedList :: insert_before_current(string element){
	if(is_empty() || current == first){
		insert_first(element);
	}
	else{
	/*
		Node *temp;
		temp = new Node(element, current, current->prev);
		current->prev->next = temp;
		current->prev = temp;
		current = temp;
		delete temp;
	*/
	current = new Node(element, current, current->prev);
	current->next->prev = current;
	current->prev->next = current;
	m_size++;
	}
}

	/*****************  Removing ***********************/
//removing the first element in the list and returning it.
string LinkedList :: remove_first(){
	if(is_empty()){
			throw ListException("remove_first()", "list is empty");
	}
	else if(m_size == 1){
		string to_get = first->element;
		first = last = current = nullptr;
		m_size--;
		return to_get;	
	}
	else {
		string pam = first->element;
		Node *ramp = first;
		first = first->next;
		delete ramp;
		m_size--;
		first->prev = nullptr;
		current = first;
		return pam;
	}	
}
//removing the last element in the list and returning it.
string LinkedList :: remove_last(){
	if(is_empty()){
		throw ListException("remove_last", "list is empty");
	}
	else if(m_size == 1){
		string temp = last->element;
		last = first = current = nullptr;
		m_size--;
		return temp;
	}
	else{
		string get = last->element;
		Node *temp = last;
		last = last->prev;
		delete temp;
		m_size--;
		last->next = nullptr;
		current = last;
		return get;
	}
}
//removing the element pointed by the current and returning it.
string LinkedList :: remove_current(){
	if(current != nullptr){
		string get;
		if(current->prev != nullptr && current->next != nullptr){
			Node *rem = current;
			get = current->element;
			current = current->prev;
			current->next = rem->next;
			rem->next->prev = current;
			delete rem;
			m_size--;
			return get;
		}
		else if(current == first){
		
			string to_return = remove_first();
			return to_return;
		}
		else if(current == last){
		
			string to_return = remove_last();
			return to_return;
		}
		
	}
	else {
		throw ListException("remove_current()", "list is empty");
	}	
	return "";	
}
//updating the element in the current position by the given element.
string LinkedList :: update_current(string element){
	if(is_empty()){
		throw  ListException("update_current()", "list is empty");
	}
	else{
		string toreturn = current->element;
		current->element = element;
		return toreturn;
	}
}

	/**************** Printing ***********************/
//printing all the contents to the console in its exact list.
void LinkedList :: print_contents() const{
	Node * wait = first;
	cout<<"List is: ";
	while(wait != nullptr){
		cout<<wait->element<<", ";
		wait = wait->next;
	}
	cout<<endl;
}
//print the list in the reverse order.
void LinkedList :: print_contents_reverse() const{
	cout<<"list in reverse is: ";
	Node *t = last;
	while(t != nullptr){
		cout<<t->element<<", ";
		t = t->prev;
	}
	cout<<endl;
	
}

