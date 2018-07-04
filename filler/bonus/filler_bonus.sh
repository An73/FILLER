#!/bin/bash

BOT=1
BOT_NAME="Abanlin"
BOT_FILE=abanlin.filler
PLAYER=1
PLAYER_BOT=2
EXIT=0
N_MAP=2
MAP="24 X 40 "
MAP_FILE=map01
COLOR_FILE=color_base.sh
COLOR=1
display_menu() {
	clear
	printf "\033[1;41;33m                                                                                                                  \n"
	printf "    1)-=>     Player: ${PLAYER}                                                                                           \n"
	printf "    2)-=>     Map: ${MAP}                                                                                       \n"
	printf "    3)-=>     Bot: \"${BOT_NAME}\"                                                                                      \n"
	printf "    4)-=>     Colors:  ${COLOR}                                                                                          \n"
	printf "    5)-=>     Start                                                                                               \n"
	printf "    6)-=>     Exit                                                                                                \n"
	printf "                                                                                                                  \n"
}

options() {
	read -n 1 VALUE
	if [[ $VALUE = "1" ]]
		then PLAYER=$[ $PLAYER + 1 ] && PLAYER_BOT=1
		if [[ $PLAYER > 2 ]]
			then PLAYER=1 && PLAYER_BOT=2
		fi
	fi

	if [[ $VALUE = "2" ]]
		then N_MAP=$[ $N_MAP + 1 ]
		if [[ $N_MAP = 1 ]]
			then MAP="15 X 17 " && MAP_FILE=map00
		fi
		if [[ $N_MAP = 2 ]]
			then MAP="24 X 40 " && MAP_FILE=map01
		fi
		if [[ $N_MAP = 3 ]]
			then MAP="100 X 99" && MAP_FILE=map02
		fi
		if [[ $N_MAP > 3 ]]
			then N_MAP=1 && MAP="15 X 17 " && MAP_FILE=map00
		fi
	fi

	if [[ $VALUE = "3" ]]
		then BOT=$[ $BOT + 1 ]
		if [[ $BOT > 6 ]]
			then BOT=1
		fi
		if [[ $BOT = 1 ]]
			then BOT_NAME="Abanlin" && BOT_FILE=abanlin.filler
		fi
		if [[ $BOT = 2 ]]
			then BOT_NAME="Carli" && BOT_FILE=carli.filler
		fi
		if [[ $BOT = 3 ]]
			then BOT_NAME="Champely" && BOT_FILE=champely.filler
		fi
		if [[ $BOT = 4 ]]
			then BOT_NAME="Grati" && BOT_FILE=grati.filler
		fi
		if [[ $BOT = 5 ]]
			then BOT_NAME="Hcao" && BOT_FILE=hcao.filler
		fi
		if [[ $BOT = 6 ]]
			then BOT_NAME="Superjeannot" && BOT_FILE=superjeannot.filler
		fi
	fi

	if [[ $VALUE = "4" ]]
		then COLOR=$[ $COLOR + 1 ]
		if [[ $COLOR > 3 ]]
			then COLOR=1
		fi
		if [[ $COLOR = 1 ]]
			then COLOR_FILE=color_base.sh
		fi
		if [[ $COLOR = 2 ]]
			then COLOR_FILE=color_1.sh
		fi
		if [[ $COLOR = 3 ]]
			then COLOR_FILE=color_2.sh
		fi
	fi

	if [[ $VALUE = "6" ]]
		then EXIT=$[ $EXIT + 1 ]
	fi

	if [[ $VALUE = "5" ]]
		then ./resources/filler_vm -f ./resources/maps/${MAP_FILE} -p${PLAYER_BOT} ./resources/players/${BOT_FILE} -p${PLAYER} ../dkotenko.filler | sh ${COLOR_FILE} 
		sleep 3s
	fi
}

while [[ $EXIT != 1 ]]
do
	display_menu
	options
done
clear