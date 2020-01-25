.name       "Batman"
.comment    "This city needs me"

loop:
        sti r1, %:live, %1    # <-- L'étiquette de boucle indique cette opération.

live:
        live %0               # <-- L'étiquette en direct indique cette opération.
        ld %0, r2             # <-- Et aucune étiquette n'indique cette opération
        zjmp %:loop