/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 23:10:43 by mgamraou          #+#    #+#             */
/*   Updated: 2025/12/23 02:58:20 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int main()
{
    std::cout << "--- TEST 1: BASICS & EQUIP ---" << std::endl;
    // 1. Create a Character
    Character* me = new Character("me");
    Character* bob = new Character("bob");

    // 2. Create Spells
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();

    // 3. Equip them
    // Inventory: [0:Ice] [1:Cure] [2:NULL] [3:NULL]
    me->equip(ice);
    me->equip(cure);

    // 4. Use them on Bob
    std::cout << "Should print ice/cure messages:" << std::endl;
    me->use(0, *bob); // "shoots an ice bolt..."
    me->use(1, *bob); // "heals bob's wounds..."
    me->use(2, *bob); // Should do nothing (empty slot)

    std::cout << "\n--- TEST 2: DEEP COPY ---" << std::endl;
    // 5. Create a Copy of 'me'
    // This triggers your Copy Constructor
    Character* meClone = new Character(*me);

    std::cout << "Original uses Ice:" << std::endl;
    me->use(0, *bob); 
    
    std::cout << "Clone uses Ice:" << std::endl;
    meClone->use(0, *bob);

    // Modify Clone's inventory to prove it's separate
    std::cout << ">> Unequipping slot 0 from Original only..." << std::endl;
    me->unequip(0); // Clone drops Ice, Original should still have it

    std::cout << "Clone using slot 0 (Should still work): ";
    meClone->use(0, *bob);
    
    std::cout << "Original using slot 0 (Should do nothing):   ";
    me->use(0, *bob);

    std::cout << "\n--- TEST 3: UNEQUIP & MEMORY ---" << std::endl;
    // 6. Unequip from Original
    // Note: In a real scenario, you must save the pointer before unequipping
    // to delete it, otherwise it leaks. For this test, we just unequip.
    me->unequip(0); // Removes Ice
    me->unequip(1); // Removes Cure
    
    me->use(0, *bob); // Should do nothing

    std::cout << "\n--- CLEANUP ---" << std::endl;
    
    delete me;
    delete meClone;
    delete bob;
    
    // IMPORTANT:
    // Since we unequipped 'ice' and 'cure' from 'me' manually, 
    // and 'meClone' made its OWN copies, the original 'ice' and 'cure'
    // pointers created at the start are now floating.
    // In a rigorous test, we would track them. 
    // For this simple test, we just delete them here to be clean:
    delete ice; 
    delete cure;

    return 0;
}
