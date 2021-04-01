//Instantiates areas at the beginning of the game so the main remains tidy.
#ifndef newarea_cpp
#define newarea_cpp
#include "newArea.hpp"


void areaSetup()
{
    //START ROOM INITIALIZATION
    area* startRoom = new area (2, 3, "Foyer");
    startRoom->setAreaDescription(
    "\nYou find yourself standing in the FOYER of the mansion. A large persian rug\n"
    "covers the hardwood floor beneath you, its colors dulled from age. The wood\n"
    "creaks with every step or shift of weight you make. Above you, a chandelier\n"
    "made from cast iron hangs and candelabras sitting in polished gold holders\n"
    "decorate the edges of the room. Although the place has been vacant for decades\n"
    "and age has dulled the interior, the atmosphere of the foyer gives off an air\n"
    "of wealth. Valuable antiques are sure to be throughout the grounds. The\n"
    "emptiness of the property can be felt in the air and it causes an eerie unease\n"
    "in your stomach. You want to leave as soon as possible - but not before\n"
    "grabbing a few valuables. Throughout the room, carved stone busts and painted\n"
    "portraits leer at you. No matter where you walk, their gaze seems to follow.\n"
    "You want to leave this area urgently.\n");

    //ROOM TO THE NORTH: SWORD ROOM INITIALIZATION
    area* swordRoom = new area (2, 2, "Storage room");
    swordRoom->setAreaDescription(
    "\nYou enter into a room that appears to be a STORAGE ROOM. Various items\n"
    "are thrown around the room creating a cluttered chaos. The majority of the\n"
    "floor is covered, making it difficult to traverse without stepping on things.\n"
    "A single path seems to be the only way to move throughout the room. Useless\n"
    "trinkets and decorations have been stacked haphazardly, obstructing your view\n"
    "and making it impossible to see where the path leads. The walls are collaged\n"
    "with antique paintings depicting various battles and scenery yet it is\n"
    "difficult to make out their composition due to the age and tear of their\n"
    "canvases. It seems this room was used strictly to store unwanted items that\n"
    "the owner could not part with. As you follow the path, you begin to notice\n"
    "various furniture such as a broken nightstand and clawed chair. Continuing\n"
    "forward, you ask yourself why the owner would keep these items rather than\n"
    "trash them, when a crashing sound causes you to jump and look to the right.\n"
    "A mouse has caused one of the trinket mountains to collapse, revealing an\n"
    "armored knight statue holding a SWORD beneath it.");
    pickup* apple1 = new pickup(*swordRoom, cure, "apple", "A shiny red apple that restores 5 health.", 5); //creates the apple
    swordRoom->addItem(*apple1);// places apple in room

    //ROOM TO THE SOUTH: GRAVEYARD/CEMETERY INITIALIZATION
    area* graveyard = new area (2, 4, "Graveyard");
    graveyard->setAreaDescription(
    "\nYou exit out the mansion doors and find yourself in the GRAVEYARD that\n"
    "surrounds the property. The air is heavy, cold and the atmosphere is damp.\n"
    "A light breeze is blowing through the surrounding forest causing water\n"
    "droplets to land on your skin. You shiver. Around you resides countless\n"
    "headstones of uniform size, each small and dull. Ahead of you is a dried-up\n"
    "stone fountain and past that are the property gates. Suddenly, a screeching\n"
    "sound resonates causing you to jump and look to the left. You notice a crow\n"
    "resting on a peculiar headstone. The crow lets out another screech before\n"
    "flying into the dark woods. However, your eyes do not follow the path of the\n"
    "crow. The statuesque headstone it was resting on has left you frozen, grounded\n"
    "to your spot. From where you are standing, the details of the statue are\n"
    "impossible to make out. All you can observe is its eerie silhouette in the\n"
    "moonlight. A distant crow lets out another screech and you regain control of\n"
    "your body with a sharp breath, but you cannot get rid of your urge to run to\n"
    "the statue. Upon approaching the figure, you notice its shape: a naked fallen\n"
    "angel, its face carved into a permanent wail gazing towards the sky. The\n"
    "statue has no markings to give away who may be buried beneath it, but her arms\n"
    "extend outward with cupped hands. The moon acts as a spotlight into her cupped\n"
    "fingers and you notice a small NECKLACE resting in her palms. The necklace chain\n"
    "is made of bone leading to a heavy pendant. The pendant has silver metalwork\n"
    "framing a crow head with a ruby in its beak.\n"
    );
    pickup* apple2 = new pickup(*graveyard, cure, "apple", "A shiny red apple that restores 5 health.", 5); //places an apple in corresponding room
    graveyard->addItem(*apple2);

    //ROOM TO THE EAST: KITCHEN INITIALIZATION
    area* kitchen = new area (1, 3, "Kitchen");
    kitchen->setAreaDescription(
    "\nYou enter into a room that appears to be a KITCHEN. The cabinets are made of\n"
    "a darkened wood with stained glass windows. Contrasting chipped marble\n"
    "accentuates the countertops and the tiled floors are composed of lightly\n"
    "colored stone. In its prime, the kitchen would have been breathtaking. However,\n"
    "the lack of use has caused it to deteriorate and its only inhabitants are the\n"
    "spiders residing in corner cobwebs. The center island houses an ornate bowl\n"
    "filled with dried, rotted fruit resulting in a pungent sweet smell lingering in\n"
    "the room. You walk closer to the center island and notice a dull KNIFE lodged in\n"
    "a chopping block, with dried blood on its edge.\n"
    );
    pickup* apple3 = new pickup(*kitchen, cure, "apple", "A shiny red apple that restores 5 health.", 5); //places an apple in corresponding room
    kitchen->addItem(*apple3);

    //ROOM TO THE WEST: LIBRARY INITIALIZATION
    area* library = new area (3, 3, "Library");
    library->setAreaDescription(
    "\nYou enter into a room that appears to be a LIBRARY. It is dimly lit, but you\n"
    "can make out an endless assortment of hardbound books displayed against each\n"
    "wall from floor to ceiling. In the center of the room, a large dark wood table\n"
    "sits, lit up by an overhanging chandelier. A thick layer of dust accompanies\n"
    "every inch of the room and cough as the dust covers your throat when you inhale.\n"
    "It smells heavy and antique in this room. Approaching the table, you can make\n"
    "out various items cluttering the edges with a leatherbound book at its center.\n"
    "The book is closed, its cover decorated in metal work with a single emerald in\n"
    "the middle. A belt buckle keeps the book closed. You feel an excited chill run\n"
    "up your arms. It's almost as if the book is whispering for you.\n"
    );
    pickup* apple4 = new pickup(*library, cure, "apple", "A shiny red apple that restores 5 health.", 5); //places an apple in corresponding room
    library->addItem(*apple4);
}
#endif