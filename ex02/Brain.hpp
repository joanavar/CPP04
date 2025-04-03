#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
protected:

    unsigned int totalIdeas;

public:
    Brain(void);
    ~Brain(void);
    Brain(const Brain &copy);
	Brain &operator=(const Brain &copy);

	std::string ideas[100];

	void setIdea(std::string &idea);
	void getIdea(int nbIdea) const;
	void getIdea(void) const;

};



#endif