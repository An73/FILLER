gren=$(printf "\033[;44;32mO\033[0m")
yel=$(printf "\033[;44;35mX\033[0m")
grens=$(printf "\033[;44;32mO\033[0m")
yel2=$(printf "\033[;44;33mX\033[0m")
dot=$(printf "\033[;44;30m \033[0m")

clear
sed "s|O|$gren|g" |
sed "s|X|$yel|g" |
sed "s|x|$yel2|g" |
sed "s|\.|$dot|g" |
sed "/^0.. /s|o|$grens|g" |
sed "s|fin|player|g" |
sed "/Plateau/d" |
sed "/Piece/,/<got/d" 

#sed "/*/d" 
#-ncurses