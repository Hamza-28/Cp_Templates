struct Point {
	int x, y;
	Point () {
		this->x = 0;
		this->y = 0;
	}	
	Point (int x, int y) {
		this->x = x;
		this->y = y;
	}	
	void operator -=(const Point& p) {
		this->x -= p.x;
		this->y -= p.y;
	}
	Point operator -(const Point& p) const {
		Point q;
		q.x = this->x - p.x;
		q.y = this->y - p.y;
		return q;
	}
	long long operator *(const Point& p) const {
		return 1LL * x * p.y - 1LL * y * p.x;
	}
	friend istream& operator >>(istream& cin, Point& p) {
		cin >> p.x >> p.y;
		return cin;
	}	
	friend ostream& operator <<(ostream& cout, const Point& p) {
		cout << p.x << " " << p.y;
		return cout;
	}
};
