#include <iostream>
#include <gecode/driver.hh>
#include <lab1.hpp>

int main(int argc, char **argv) {
	gameai::gecode::lab1 l1;
	Gecode::DFS<decltype(l1)> e(&l1);
	if(decltype(l1) *s = e.next()) {
		s->print(std::cout);
	}
	return 0;
}
