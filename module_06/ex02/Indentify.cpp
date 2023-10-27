/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Indentify.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:51:26 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/09/20 21:32:20 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Indentify.hpp"
#include <cmath>

Base* generate() {
	srand(static_cast<unsigned>(time(nullptr)));
    int random = rand() % 3;

    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != nullptr)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != nullptr)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != nullptr)
        std::cout << "C" << std::endl;
}

void identify(Base& p) {
    try {
        static_cast<void>(dynamic_cast<A&>(p));
        std::cout << "A" << std::endl;
    } catch (std::bad_cast&) {
        try {
            static_cast<void>(dynamic_cast<B&>(p));
            std::cout << "B" << std::endl;
        } catch (std::bad_cast&) {
            try {
                static_cast<void>(dynamic_cast<C&>(p));
                std::cout << "C" << std::endl;
            } catch (std::bad_cast&) {
                std::cerr << "Unknown type" << std::endl;
            }
        }
    }
}