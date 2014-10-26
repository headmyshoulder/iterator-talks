cmake_minimum_required ( VERSION 2.8 )

project ( talk_meetingcpp_2014 )

find_package ( LATEX )

if ( LATEX_COMPILER )

  include ( UseLATEX.cmake )

  add_latex_document ( talk.tex
    IMAGES 
      ambrosys.png
    DEFAULT_PDF
    MANGLE_TARGET_NAMES
  )

endif ( LATEX_COMPILER )


add_subdirectory ( snippets )