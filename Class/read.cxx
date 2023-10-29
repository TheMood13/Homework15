#include "Event.h"

void read() {

    // Initialize your object
    Event *event{nullptr};
    // open your file
    auto file = TFile::Open("tree_file.root");
    // get your tree
    TTree *Tree = static_cast<TTree*>(file->Get("Tree"));
    // remember to set the branch address
    Tree->SetBranchAddress("event", &event);
    Long64_t N = Tree->GetEntries;

    TH2 *h2 = new TH2("h2", "py vs px; py; px", 100, 0, .02);
    for (Int_t i{0}; i<N; i++) { // loop over the whole tree
        Tree->GetEntry(i);
        // do something
        h2->Fill(event);
    }
    h2->Draw();
}