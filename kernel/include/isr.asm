extern division_error_handler
;colocar extern da func do ero
global ir0

ir0:
    pushad

    call division_error_handler
    ;call nome da func
    popad
    iret