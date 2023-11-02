## unordered_map<char, int> count;

est une déclaration en C++ qui crée une instance de la classe unordered_map (qui est une structure de données de type dictionnaire) appelée count. Cette ligne de code déclare une variable nommée count qui est un conteneur associatif, associant des caractères (char) à des entiers (int).

En d'autres termes, cette ligne de code crée une structure de données qui peut être utilisée pour compter le nombre d'occurrences de chaque caractère (lettre) dans un contexte donné. Par exemple, vous pouvez utiliser count['a'] pour obtenir le nombre d'occurrences du caractère 'a'.

Le choix d'utiliser unordered_map (qui est une variante de std::map dans le langage C++) est souvent fait en fonction de la performance. Les éléments dans un unordered_map ne sont pas stockés dans un ordre particulier, mais ils permettent des recherches rapides. Cela les rend adaptés à de nombreuses tâches de comptage, de suivi des occurrences, et de gestion de données associatives en général.

## for (auto x : s)

auto : Le mot-clé auto est utilisé pour déduire automatiquement le type de données de chaque élément de la séquence s. Cela signifie que vous n'avez pas besoin de spécifier explicitement le type de x, il sera déduit automatiquement en fonction du type d'éléments dans s.

x : C'est la variable qui prend la valeur de chaque élément de la séquence s à chaque itération de la boucle.

s : C'est la séquence que vous souhaitez parcourir. Cela peut être un tableau, un conteneur (comme un vecteur, une liste, un ensemble, etc.), ou toute autre structure de données qui prend en charge l'itération

## if (x.second != 0)

x : Il s'agit généralement d'une paire clé-valeur extraite d'une structure de données associative (comme une std::unordered_map ou une std::map). La première partie de la paire (x.first) est généralement la clé, et la deuxième partie (x.second) est la valeur associée.

x.second : Cela fait référence à la deuxième partie de la paire x, c'est-à-dire la valeur associée à la clé.


