/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:51:58 by gneto-co          #+#    #+#             */
/*   Updated: 2024/11/07 11:06:51 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
#define COLORS_H

// cursor moving

#define MOVE_CURSOR_UP(x) std::cout << "\033[" << x << "A"
#define MOVE_CURSOR_DOWN(x) std::cout << "\033[" << x << "B"
#define MOVE_CURSOR_RIGHT(x) std::cout << "\033[" << x << "C"
#define MOVE_CURSOR_LEFT(x) std::cout << "\033[" << x << "D"

#define CURSOR_ALL_LEFT "\033[0G"

#define CLEAR_SCREEN_FORWARD_CURSOR "\033[J"
#define CLEAR_LINE_FORWARD_CURSOR "\033[K"
#define CLEAR_LINE_BACK_CURSOR "\033[1K"
#define CLEAR_ACTUAL_LINE "\033[0K"


// Text Format
// -Colors
// --Text (30-37):
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
// --Background (40-47):
#define BLACK_BACKGROUND "\033[40m"
#define RED_BACKGROUND "\033[41m"
#define GREEN_BACKGROUND "\033[42m"
#define YELLOW_BACKGROUND "\033[43m"
#define BLUE_BACKGROUND "\033[44m"
#define MAGENTA_BACKGROUND "\033[45m"
#define CYAN_BACKGROUND "\033[46m"
#define WHITE_BACKGROUND "\033[47m"

/*
Formatação de Texto
\033[1m: Texto em negrito.
\033[2m: Texto em brilho reduzido (fino).
\033[3m: Texto em itálico.
\033[4m: Texto sublinhado.
\033[5m: Texto a piscar.
\033[7m: Inverte as cores (texto claro em fundo escuro e vice-versa).
\033[8m: Esconde o texto (pode não funcionar em todos os terminais).
\033[9m: Texto riscado.
*/

#endif