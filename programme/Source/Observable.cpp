#include "Observable.h"

/**
 * @brief Ajoute un observateur à la liste des observateurs de l'objet.
 *
 * Cette méthode permet d'enregistrer un observateur qui sera notifié 
 * lors de tout changement d'état de l'objet grille.
 *
 * @param observer Pointeur vers l'objet observateur à ajouter.
 */
void Observable::AjtObservateurs(Observer* observer) {
    list_observers.push_back(observer);
}