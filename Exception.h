
class Exception {
	public:
		string msg;
		Exception() {}
		Exception(string msg) {
			this->msg = "Exception:: "+msg;
		}
		
};

class SizeException : public Exception{
	public:
		SizeException(){}
		SizeException(string msg) {
			this->msg = "SizeException:: "+msg;
		}
};

