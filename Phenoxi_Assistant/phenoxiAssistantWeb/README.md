Install all requirements first.
pip install -r requirements.txt

Setup Backend:

bash
cd backend
python -m venv venv
source venv/bin/activate  # On Windows: venv\Scripts\activate
python app.py -- this will activate the python backend that we run.


Setup Frontend:
Open frontend/index.html in a web browser

Or serve it using a local server: python -m http.server 3000

Access: Open http://localhost:3000 in your browser