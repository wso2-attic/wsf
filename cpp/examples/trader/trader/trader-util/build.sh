
    g++ -g -o ExchangeTrader.out -I$WSFCPP_HOME/include -I$WSFCPP_HOME/include/axis2-1.6.0 -I$WSFCPP_HOME//include/axis2-1.6.0/platforms -Isrc -L$WSFCPP_HOME/lib \
        -laxutil \
        -laxis2_axiom \
        -laxis2_engine \
        -laxis2_parser \
        -lpthread \
        -laxis2_http_sender \
        -laxis2_http_receiver \
        -lguththila \
        -lwso2_wsf \
        *.cpp src/*.cpp
    