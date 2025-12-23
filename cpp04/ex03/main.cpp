/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 23:10:43 by mgamraou          #+#    #+#             */
/*   Updated: 2025/12/23 01:44:45 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp" // Required for the parameter type

// 1. Create a dummy class just so we can pass something to use()
// Since ICharacter is an interface, we MUST implement its pure virtuals
// to instantiate it, even if they do nothing.
class DummyCharacter : public ICharacter {
public:
    virtual ~DummyCharacter() {}
    virtual std::string const & getName() const { 
        static std::string name = "Bob_The_Dummy"; 
        return name; 
    }
    virtual void equip(AMateria* m) { (void)m; }
    virtual void unequip(int idx) { (void)idx; }
    virtual void use(int idx, ICharacter& target) { (void)idx; (void)target; }
};

int main()
{
    std::cout << "=== TESTING AMATERIA LOGIC ===\n";

    // 1. Test Constructors and Polymorphism
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();
    
    std::cout << "Type 1: " << ice->getType() << " (Expected: ice)" << std::endl;
    std::cout << "Type 2: " << cure->getType() << " (Expected: cure)" << std::endl;

    // 2. Test Cloning (Deep Copy)
    // clone() should return a NEW pointer, not the same address
    AMateria* iceClone = ice->clone();
    
    std::cout << "\n[Cloning Test]" << std::endl;
    std::cout << "Original Address: " << ice << std::endl;
    std::cout << "Clone Address:    " << iceClone << std::endl;

    if (ice != iceClone) 
        std::cout << "SUCCESS: Clone returned a new memory address." << std::endl;
    else 
        std::cout << "FAILURE: Clone returned the same address!" << std::endl;

    if (iceClone->getType() == "ice")
        std::cout << "SUCCESS: Clone preserved the correct type." << std::endl;

    // 3. Test Use()
    // This confirms your Ice.cpp / Cure.cpp are linked correctly
    DummyCharacter bob;
    std::cout << "\n[Action Test]" << std::endl;
    ice->use(bob);       // Should print: * shoots an ice bolt at Bob_The_Dummy *
    cure->use(bob);      // Should print: * heals Bob_The_Dummy's wounds *
    iceClone->use(bob);  // Should work exactly like the original

    // 4. Cleanup (Check for leaks with Valgrind/Leaks)
    delete ice;
    delete cure;
    delete iceClone;

    std::cout << "\n=== TESTS FINISHED ===" << std::endl;
    return 0;
}
