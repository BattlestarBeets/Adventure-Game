//Instantiates areas at the beginning of the game so the main remains tidy.
#ifndef newarea_cpp
#define newarea_cpp
#include "newArea.hpp"


void areaSetup()
{
    //START ROOM INITIALIZATION
    area* startRoom = new area (2, 3, "Foyer");
    startRoom->setAreaDescription(
    "\nYou find yourself standing in the 'foyer' of the mansion. A large persian rug covers the hardwood floor beneath you,\n"
    "its colors dulled from age. The wood creaks with every step or shift of weight you make. Above you, a candle chandelier \n"
    "made from cast iron hangs and candelabras sitting in polished gold holders decorate the edges of the room. Although the \n"
    "place has been vacant for decades and age has dulled the interior, the atmosphere of the foyer gives off an air of wealth.\n"
    "Valuable antiques are sure to be throughout the grounds. The emptiness of the property can be felt in the air and it \n"
    "causes an eerie unease in your stomach. You want to leave as soon as possible but not after grabbing a few valuables. \n"
    "Throughout the room, carved stone busts and painted portraits leer at you. No matter where you walk, their gaze seems to \n"
    "follow. You want to leave this area urgently. To your left ('west'), a heavy wooden door stands with a bronze knob. \n"
    "Another door lies ahead of you ('north') but this door is not as imposing as the previous. Aside from the grand double \n"
    "doors ('south') that you entered through, a final decorative swinging door can be seen to your right ('east').\n"
    );

    //ROOM TO THE NORTH: SWORD ROOM INITIALIZATION
    area* swordRoom = new area (2, 2, "Storage room");
    swordRoom->setAreaDescription(
    "\nYou enter into a room that appears to be a ‘storage room’. Various items are thrown around the room creating a cluttered \n"
    "chaos. The majority of the floor is covered, making it difficult to traverse without stepping on things. A single path \n"
    "has been carved and seems to be the only way to move throughout the room. Useless trinkets and decorations have been \n"
    "stacked haphazardly obstructing your view and making it impossible to see where the path leads. The walls are collaged \n"
    "with antique paintings depicting various battles and scenery yet it is difficult to make out their composition due to the \n"
    "age and tear of their canvases. It seems this room was used strictly to store unwanted items that the owner could not part \n"
    "with. As you follow the path, you begin to notice various furniture such as a broken 'nightstand' and clawed 'chair'. \n"
    "Continuing forward, you ask yourself why the owner would keep these items rather than trash them when a crashing sound causes \n"
    "you to jump and look to the right. A mouse has caused one of the trinket mountains to collapse revealing an armored knight statue \n"
    "holding a 'sword' beneath it. The avalanche has caused the path you were on to change. The path you are on has split into two. \n"
    "One of the paths leads to a barely noticeable door (‘east’) with a creaking sound coming from behind it. The other path leads \n"
    "to an unlit, dark hallway ('north'). When you look into the dark, you cannot help but feel tense. You sense something is staring \n"
    "at you from deep within the corridor.\n"
    );
    pickup* apple1 = new pickup(*swordRoom, cure, "apple", "A shiny red apple that restores 5 health.", 5); //creates the apple
    swordRoom->addItem(*apple1);// places apple in room

    //ROOM TO THE SOUTH: GRAVEYARD/CEMETERY INITIALIZATION
    area* graveyard = new area (2, 4, "Graveyard");
    graveyard->setAreaDescription(
    "\nYou exit out the mansion doors and find yourself in the 'cemetery' that surrounds the property. The air is heavy, cold \n"
    "and the atmosphere is damp. A light breeze is blowing through the surrounding forest causing water droplets to land on \n"
    "your skin. You shiver. Around you resides countless headstones of uniform size, each small and dull. Ahead of you is a \n"
    "dried, stone fountain and past that are the property gates ('south'). Suddenly, a screeching sound resonates causing you \n"
    "to jump and look to the left. You notice a crow resting on a peculiar headstone. The crow lets out another screech before \n"
    "flying into the dark woods. However, your eyes do not follow the path of the crow. The statuesque headstone it was resting \n"
    "on has left you frozen, grounded to your spot. From where you are standing, the details of the statue are impossible to \n"
    "make out. All you can observe is it’s eerie silhouette in the moonlight. A distant crow lets out another screech and you \n"
    "regain control of your body with a sharp breath, but you cannot get rid of your urge to run to the statue. Upon approaching \n"
    "the figure, you notice its shape: a naked fallen angel, it’s face carved into a permanent wail gazing towards the sky. \n"
    "Behind the statue resides the grounds garden ('east'). The 'fallen angel statue' has no markings to give away who may be buried \n"
    "beneath it, but her arms extend outward with cupping hands. The moon acts as a spotlight into her cupped fingers and you notice \n"
    "a small necklace resting in her palms. The necklace chain is made of small bone leading to a heavy pendant. The 'pendant' has \n"
    "silver metalwork framing the skeleton of a crow head with a ruby gem in its beak.\n"
    );
    pickup* apple2 = new pickup(*graveyard, cure, "apple", "A shiny red apple that restores 5 health.", 5); //places an apple in corresponding room
    graveyard->addItem(*apple2);

    //ROOM TO THE EAST: KITCHEN INITIALIZATION
    area* kitchen = new area (1, 3, "Kitchen");
    kitchen->setAreaDescription(
    "\nYou enter into a room that appears to be a 'kitchen'. The 'cabinets' are made of a darkened wood with stained glass windows. \n"
    "Contrasting chipped marble accentuates the countertops and the tiled floors are composed of lightly colored stone. In its prime, \n"
    "the kitchen would have been breathtaking. However, the lack of use has caused it to deteriorate and its only inhabitants are \n"
    "the spiders residing in corner cobwebs. The center island houses an ornate 'bowl' filled with dried, rotted fruit resulting in a \n"
    "pungent sweet smell lingering in the room. A small door ('north') is tucked out of sight and would have gone unnoticed had there \n"
    "not been a creaking sound coming from behind it. On another wall, a grand double door ('east') is slightly ajar with a dim light \n"
    "shining through, exposing a moving shadow behind them. You walk closer to the center island and notice a dull 'blade' lodged into \n"
    "a chopping block with dried blood on its edge. The shadows and creaking noises behind the doors has made your skin crawl. \n"
    "Arming yourself might be smart.\n"
    );
    pickup* apple3 = new pickup(*kitchen, cure, "apple", "A shiny red apple that restores 5 health.", 5); //places an apple in corresponding room
    kitchen->addItem(*apple3);

    //ROOM TO THE WEST: LIBRARY INITIALIZATION
    area* library = new area (3, 3, "Library");
    library->setAreaDescription(
    "\nYou enter into a room that appears to be a ‘library’. It is dimly lit, but you can make out an endless assortment of hardbound books \n"
    "displayed against each wall from floor to ceiling. In the center of the room, a large dark wood ‘table’ sits, lit up by an overhanging \n"
    "candle chandelier. A thick layer of dust accompanies every inch of the room and you make a short cough as the dust covers your throat \n"
    "when you inhale. It smells heavy and antique in this room. On the far end of the room (‘west’), a faint outline of a door is present and \n"
    "you can hear a light thudding sound coming from it’s other side. Approaching the table, you can make out various items cluttering the \n"
    "edges with a leatherbound book at its center. The book is closed, its cover decorated in metal work with a single emerald in the middle. \n"
    "A belt buckle keeps the book closed. You feel an excited chill run up your arms. It's almost as if the book is whispering for you.\n"
    );
    pickup* apple4 = new pickup(*library, cure, "apple", "A shiny red apple that restores 5 health.", 5); //places an apple in corresponding room
    library->addItem(*apple4);


    //ROOM NORTH OF SWORD ROOM: CORRIDOR
    area* corridor = new area(2, 1, "Corridor");
    corridor->setAreaDescription("\nYou walk deeper into a 'corridor'. It is dimly lit and damp. You hear a scurrying sound.\n");
    mob* rat1 = new mob("rat", "A large rat the size of a dog with saliva dripping from its fangs.", 5, 2); //creates enemy
    corridor->addEnemy(rat1); //puts enemy in room
        
}
#endif