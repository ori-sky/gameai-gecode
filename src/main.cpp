#include <iostream>
#include <gecode/driver.hh>
#include <lab1.hpp>
#include <lab2.hpp>

int main(int argc, char **argv) {
	gameai::gecode::lab1 l1;
	Gecode::DFS<decltype(l1)> e1(&l1);
	while(decltype(l1) *s = e1.next()) {
		s->print(std::cout);
	}

	gameai::gecode::lab2 l2;
	Gecode::DFS<decltype(l2)> e2(&l2);
	while(decltype(l2) *s = e2.next()) {
		s->print(std::cout);
	}

	return 0;
}
