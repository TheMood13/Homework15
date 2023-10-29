#include <iostream>
#include <vector>
#include "Event.h"

using namespace std;

void write() {
    // Initialize your object e.g. as a pointer
    Event *event{nullptr};
    // Create your root file here
    Tfile f("tree_file.root", "tree");
    // Create your TTree here
    TTree *Tree = new TTrea("Tree", "Event Tree");
    Tree->Branch("event", &event);
    // And the associated branches underneath
    // for example a branch with your personal object type
    Double_t px;
    Double_t py;
    Double_t pz;

    // Now we create our loop for filling the tree with some random data
    // For loop here
    Int_t nEvents{10000};
    for (Int_t i{0}; i<nEvents; i++){ // define how many events you want
        // Initialize your new object below
        px = gRandom->Gaus(0,.02);
        py = gRandom->Gaus(0,.02);
        pz = gRandom->Gaus(0,.02);
        event = new Event(px,py,pz);
        // Now fill tree
        Tree->Fill();
        // Remember to delete it again otherwise you will have memory leak!
        delete event;
    }
    // save the tree/file
    Tree->AutoSave();
}