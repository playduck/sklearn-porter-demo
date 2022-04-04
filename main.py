import os
from sklearn.datasets import load_iris
from sklearn.tree import DecisionTreeClassifier
from sklearn_porter import Porter
from sklearn.model_selection import train_test_split

print("Loading Dataset")
samples = load_iris()
X, y = samples.data, samples.target
X_train, X_test, y_train, y_test = train_test_split(X,y, random_state = 50, test_size = 0.5)

print("Fitting Dataset")
clf = DecisionTreeClassifier()
clf.fit(X_train, y_train)

print("Score: ", clf.score(X_test,y_test))

print("Example Test Data: ")
for i in range(5):
    X_values_formatted = ["%.4f" % x for x in X_test[i]]
    X_values_string = " ".join(X_values_formatted)
    print(f"{i}: {X_values_string} -> {y_test[i]}")

print("Exporting")
porter = Porter(clf, language="c")
output = porter.export(embed_data=True)

print("Saving file")
with open("main.c", "w") as f:
    f.write(output)

print("Done")
