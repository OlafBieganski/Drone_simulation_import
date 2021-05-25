#include "../inc/Scene.hh"

void Scene::drawAll(){
    for(DrawingInterface* & x: toDraw){
        x->draw();
    }
}

uint Scene::add_LS_item(){

}

uint Scene::rm_LS_item(){
    
}