#ifndef _IDENTIFICATION_TABLE
#define _IDENTIFICATION_TABLE
#include "IdEntry.h"
#include "../AST/Declaration.h"
#include <string>

using namespace std;

class IdentificationTable {

  int level;
  IdEntry* latest;

public:
		
IdentificationTable () {
    level = 0;
    latest = NULL;
	 }

  // Opens a new level in the identification table, 1 higher than the
  // current topmost level.

void openScope () {
    level ++;
	}

  // Closes the topmost level in the identification table, discarding
  // all entries belonging to that level.

void closeScope () {

    IdEntry* entry;
	  IdEntry* local;

    // Presumably, idTable.level > 0.

    entry = this->latest;

    while (entry->level == this->level) {
		local = entry;
		entry = local->previous;
		}

    this->level--;
    this->latest = entry;
  }

  // Makes a new entry in the identification table for the given identifier
  // and attribute. The new entry belongs to the current level.
  // duplicated is set to to true iff there is already an entry for the
  // same identifier at the current level.


void enter (string id, Declaration* attr) {

    IdEntry* entry = this->latest;
    bool present = false;
	  bool searching = true;

    // Check for duplicate entry ...
    while (searching) {
      if (entry == NULL || entry->level < this->level)
        searching = false;
      else if (entry->id == id) {
        present = true;
        searching = false;
      }
      else
        entry = entry->previous;
		}

    attr->duplicated = present;
    // Add new entry ...

    entry = new IdEntry(id, attr, this->level, this->latest);
    this->latest = entry;
    entry->print();


  }

  // Finds an entry for the given identifier in the identification table,
  // if any. If there are several entries for that identifier, finds the
  // entry at the highest level, in accordance with the scope rules.
  // Returns NULL iff no entry is found.
  // otherwise returns the attribute field of the entry found.

  Declaration* retrieve (string id) {

    IdEntry* entry;
    Declaration* attr = NULL;
    bool present = false;
	  bool searching = true;

    entry = this->latest;
    // cout << endl<< "search id: \'" << id << "\'"<<endl<<endl;
    while (searching) {
      entry->print();
      // cout << "test: "<< (id == "x") << endl;
      if (entry == NULL)
        searching = false;
      else if (entry->id == id) {
        // printf("we found it\n");
        present = true;
        searching = false;
        attr = entry->attr;
        }
      else
        entry = entry->previous;
		}

    return attr;
  }

};
#endif
