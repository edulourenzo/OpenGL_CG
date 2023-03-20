#$0 = nome do script
#$1 = primeiro parâmetro

#remove todos os caracteres a partir do "."
NAME="${1%%.*}"

LIBS="-lGL -lGLU -lglut"

echo "Compilando $NAME.c"

gcc -c $NAME.c $LIBS

echo "Montando $NAME.o"

gcc -o $NAME $NAME.o $LIBS

echo "Executando..."

./$NAME

echo "Finalizando Script!"

