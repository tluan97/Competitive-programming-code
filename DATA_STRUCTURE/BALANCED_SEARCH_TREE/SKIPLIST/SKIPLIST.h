
struct Skip_lists;
struct Column;
struct Cell;

struct Skip_lists {
	static const int MAX_LEVEL = 20;
	Column *head, *tail;
	
	Skip_lists();
	bool empty();
	Column *lower_bound(int);
	Column *upper_bound(int);
	void insert(int);
	void erase(int);
};
struct Column {
	int value;
	vector<Cell> cells;
};
struct Cell {
	Column *previous_column, *next_column;
};

Skip_lists::Skip_lists() {
	head = new Column;
	tail = new Column;
	head->value = 0;
	tail->value = 0;
	for(int i = 0; i < MAX_LEVEL; i++) {
		head->cells.push_back((Cell){NULL, tail});
		tail->cells.push_back((Cell){head, NULL});
	}
}
bool Skip_lists::empty() {
	return head->cells[0].next_column == tail;
}
Column *Skip_lists::lower_bound(int value) {
	Column *iter = head;
	for(int level = MAX_LEVEL - 1; level >= 0; level--) {
		while(iter->cells[level].next_column != tail && 
		iter->cells[level].next_column->value < value) {
			iter = iter->cells[level].next_column;
		}
	}
	return iter->cells[0].next_column;
}
Column *Skip_lists::upper_bound(int value) {
	Column *iter = head;
	for(int level = MAX_LEVEL - 1; level >= 0; level--) {
		while(iter->cells[level].next_column != tail && 
		iter->cells[level].next_column->value <= value) {
			iter = iter->cells[level].next_column;
		}
	}
	return iter->cells[0].next_column;
}
void Skip_lists::insert(int value) {
	Column *temp = lower_bound(value);
	if(temp != tail && temp->value == value) {
		return;
	}
	Column *inserted_column = new Column;
	inserted_column->value = value;
	inserted_column->cells.push_back((Cell){NULL, NULL});
	while(inserted_column->cells.size() < MAX_LEVEL && 
			rand() % 2 == 0) {
	inserted_column->cells.push_back((Cell){NULL, NULL});
	}
	Column *iter = head;
	for(int level = MAX_LEVEL - 1; level >= 0; level--) {
		while(iter->cells[level].next_column != tail && 
		iter->cells[level].next_column->value < value) {
			iter = iter->cells[level].next_column;
		}
		if(level < inserted_column->cells.size()) {
			Column *next_iter = iter->cells[level].next_column;
			iter->cells[level].next_column = inserted_column;
			next_iter->cells[level].previous_column = inserted_column;
			inserted_column->cells[level].previous_column = iter;
			inserted_column->cells[level].next_column = next_iter;
		}
	}
}
void Skip_lists::erase(int value) {
	Column *erased_column = lower_bound(value);
	if (erased_column == tail || 
		erased_column->value != value) {
		return;
	}
	Column *iter = head;
	for(int level = MAX_LEVEL - 1; level >= 0; level--) {
		while(iter->cells[level].next_column != tail && 
		iter->cells[level].next_column->value <= value) {
			iter = iter->cells[level].next_column;
		}
		if(iter == erased_column) {
			Column *previous_iter = iter->cells[level].previous_column;
			Column *next_iter = iter->cells[level].next_column;
			previous_iter->cells[level].next_column = next_iter;
			next_iter->cells[level].previous_column = previous_iter;
		}
	}
	delete erased_column;
}
Skip_lists sl;
void CPPSET(){
	int query_type, value;
	while(cin >> query_type) {
		if(query_type == 0) {
			break;
		} else if(query_type == 1) {
			cin >> value;
			sl.insert(value);
		} else if(query_type == 2) {
			cin >> value;
			sl.erase(value);
		} else if(query_type == 3) {
			if(sl.empty()) {
				cout << "empty\n";
			} else {
				cout << sl.head->
				cells[0].next_column->value << "\n";
			}
		} else if(query_type == 4) {
			if(sl.empty()) {
				cout << "empty\n";
			} else {
				cout << sl.tail->
				cells[0].previous_column->value << "\n";
			}
		} else if(query_type == 5) {
			cin >> value;
			if(sl.empty()) {
				cout << "empty\n";
			} else {
				Column *found_column = sl.upper_bound(value);
				if(found_column == sl.tail) {
					cout << "no\n";
				} else {
					cout << found_column->value << "\n";
				}
			}
		} else if(query_type == 6) {
			cin >> value;
			if(sl.empty()) {
				cout << "empty\n";
			} else {
				Column *found_column = sl.lower_bound(value);
				if(found_column == sl.tail) {
					cout << "no\n";
				} else {
					cout << found_column->value << "\n";
				}
			}
		} else if(query_type == 7) {
			cin >> value;
			if(sl.empty()) {
				cout << "empty\n";
			} else {
				Column *found_column = 
					sl.lower_bound(value)->
					cells[0].previous_column;
				if(found_column == sl.head) {
					cout << "no\n";
				} else {
					cout << found_column->value << "\n";
				}
			}
		} else {
			cin >> value;
			if(sl.empty()) {
				cout << "empty\n";
			} else {
				Column *found_column = 
					sl.upper_bound(value)->
					cells[0].previous_column;
				if(found_column == sl.head) {
					cout << "no\n";
				} else {
					cout << found_column->value << "\n";
				}
			}
		}
	}
}
