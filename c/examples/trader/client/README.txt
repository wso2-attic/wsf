Trader Client Sample
---------------------

Use the '-h' option with the sample to get help on command line options.
e.g.
./trader -h

Following 3 operations can be done with Trader Client.

Create Account
----------------
./trader [create-account] [username] [password] [endpoint_url]

eg:- ./trader create-account user password http://localhost:9090/axis2/services/traderclient


Buy
---

./trader [buy] [username] [password] [symbol] [quantity] [endpoint_url]

eg:- ./trader buy user password aa 2 http://localhost:9090/axis2/services/traderclient

Sell
----

./trader sell user password aa 1 http://localhost:9090/axis2/services/traderclient

