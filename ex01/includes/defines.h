/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:51:58 by gneto-co          #+#    #+#             */
/*   Updated: 2024/11/07 10:43:53 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
#define DEFINES_H

#define ADD "ADD"
#define SEARCH "SEARCH"
#define EXIT "EXIT"

#define MAIN_MESSAGE "ADD\t\tadd a new contact\nSEARCH\t\tsee your contact informations\nEXIT\t\tclose the program\n"
#define CONTACT_MESSAGE "[1~8]\t\tsee contact\n[0]\t\tback to menu\n"

#define EOF_MESSAGE RED "(^D) exiting phonebook..." RESET
#define EXIT_MESSAGE RED "(EXIT) exiting phonebook..." RESET

#define CONTACT_ERROR_MESSAGE RED "You must add the contact first and only then search for it, duh" RESET
#define INVALID_INPUT_MESSAGE RED "Thats not a number" RESET

#define PROMPT YELLOW "\n$>" CLEAR_LINE_FORWARD_CURSOR RESET

#endif