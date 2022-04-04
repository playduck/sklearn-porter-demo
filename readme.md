# sklearn-porter-demo

This project demonstrates generating `C` source code from a sklearn model using `sklearn-porter` on python 3.


## Usage

1. Create a `virtual enviornment`
2. Install dependencies
3. Run the python script
4. Compile and execute the C Code

```bash
python -m venv venv
# activation depends on shell
source ./venv/bin/activate

# install dependencies
pip install git+https://github.com/playduck/sklearn-porter.git

# generate model and code
python main.py

# compile
make

# run
./bin/main 5.4000 3.4000 1.7000 0.2000 # -> 0
./bin/main 5.6000 3.0000 4.1000 1.3000 # -> 1
./bin/main 6.5000 3.0000 5.2000 2.0000 # -> 2
```
