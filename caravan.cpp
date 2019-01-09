/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			caravan.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "caravan.h"
#include "general.h"
#include <stdlib.h>

struct NodeImp{
  PackAnimal pack_animal;
  Node next;
};

struct CaravanImplementation{
  Node head;
  int length;
};

Caravan new_caravan()
{
  Caravan caravan = (Caravan) malloc(sizeof(struct CaravanImplementation));
  caravan->head = 0;
  caravan->length = 0;
  return caravan;
}

int get_length(Caravan caravan)
{
  return caravan->length;
}

void delete_caravan(Caravan caravan)
{
  Node current = caravan->head;
  while (current != 0) {
    sfree(current);
    current = current->next;
  }
  sfree(caravan);
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if (animal == 0) {
    return;
  }
  else{
    Node current = caravan->head;
    Node node = (Node) malloc(sizeof(struct NodeImp));
    node->pack_animal = animal;
    node->next = 0;
    if (caravan->head == 0) {
      caravan->head = node;
    }
    else{
      while (current->next != 0) {
        current = current->next;
      }
      if (current->pack_animal == animal) {
        return;
      }
      current->next =  node;
    }
    add_to_caravan(animal, caravan);
    caravan->length++;
  }
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  Node current = caravan->head;
  if (animal == 0) {
    return;
  }
  if (caravan->head != 0 && caravan->head->pack_animal == animal) {
    caravan->head = current->next;
    sfree(current);
    remove_from_caravan(animal, caravan);
    caravan->length--;
  }
}

int get_caravan_load(Caravan caravan)
{
  int loaded = 0;
  Node current = caravan->head;
  while (current != 0) {
    loaded+=get_load(current->pack_animal);
    current=current->next;
  }
  return loaded;
}

void unload(Caravan caravan)
{
  Node current = caravan->head;
  while (current != 0) {
    unload(current->pack_animal);
    current = current->next;
  }
}

int get_caravan_speed(Caravan caravan)
{
  Node current = caravan->head;
  int speed = get_actual_speed(current->pack_animal);
  while (current->next != 0) {
    if (speed > get_actual_speed(current->next->pack_animal)) {
      speed = get_actual_speed(current->next->pack_animal);
    }
    current = current->next;
  }
  return speed;
}

void optimize_load(Caravan caravan) {

}
//
