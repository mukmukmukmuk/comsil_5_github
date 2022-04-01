#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

template <typename T>
//LinkedList class를 상속받음
class Stack : public LinkedList<T>{
	public:
		bool Delete (T &element){
			//first가 0이면 false반환
			if(this->first == 0) return false;

			// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
			element=(this->first)->data; //element에 first가 가리키는 곳의 data를 저장
			Node<T>* current=this->first; // current가 first가 가리키는 곳을 가리키게 함
			this->first = current->link; // current->link를 first가 가리키게 함
			delete current; // current에 대한 메모리 반납
			this->current_size--; //current_size를 1 감소시킴

			return true;
			}
};
