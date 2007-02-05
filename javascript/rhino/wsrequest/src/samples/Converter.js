/*
 * Copyright 2005,2006 WSO2, Inc. http://www.wso2.org
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

importClass(Packages.org.apache.axiom.om.OMElement);
importClass(Packages.org.apache.axiom.om.xpath.AXIOMXPath);
importClass(Packages.org.apache.axiom.om.impl.builder.StAXOMBuilder);

importPackage(Packages.javax.swing);
importClass(java.io.File);
importClass(java.io.FileInputStream);
importClass(java.util.List);

// Load WSRequest.js
load(["src/WSRequest.js"]);

function Converter(){
    // instantiates three WSRequest objects
    var req1 = new WSRequest();
    var req2 = new WSRequest();
    var convReq = new WSRequest();


    var fromCombo;
    var toCombo;
    var amountText;
    var resultText;
    var invokeButton;
    this.init = function init() {
        var frame = new JFrame("Currency Converter Client");
        frame.getContentPane().add(_createUI());
        frame.setSize(340, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }

    /* private method _createUI()
     * returns a JPanel object with UI components
    */
    function _createUI(){
        var pane = new JPanel(null);

        var label = new JLabel("From ", JLabel.RIGHT);
        label.setBounds(10, 10, 40, 20);
        pane.add(label);

        fromCombo = new JComboBox();
        fromCombo.setBounds(70, 10, 250, 20);
        pane.add(fromCombo);

        label = new JLabel("To ", JLabel.RIGHT);
        label.setBounds(10, 40, 40, 20);
        pane.add(label);

        toCombo = new JComboBox();
        toCombo.setBounds(70, 40, 250, 20);
        pane.add(toCombo);

        label = new JLabel("Amount", JLabel.RIGHT);
        label.setBounds(0, 80, 60, 20);
        pane.add(label);

        amountText = new JTextArea();
        amountText.setBounds(70, 80, 80, 20);
        pane.add(amountText);

        label = new JLabel("Result", JLabel.RIGHT);
        label.setBounds(170, 80, 60, 20);
        pane.add(label);

        resultText = new JTextArea();
        resultText.setBounds(240, 80, 80, 20);
        pane.add(resultText);

        invokeButton = new JButton("Invoke");
        invokeButton.setBounds(190, 130, 130, 25);
        pane.add(invokeButton);

        invokeButton.addActionListener(function(){
            _handleInvoke();
        })

        var f = new File("src/samples/countries.xml");
        try {
            var instream = new FileInputStream(f);
            var doc = new StAXOMBuilder(instream).getDocumentElement();
            var xpathExpression = new AXIOMXPath ("/Countries/Table/Name");
            var nodes = xpathExpression.selectNodes(doc);
            for (var i = 0; i < nodes.size(); i++) {
                var name = nodes.get(i).getText();
                fromCombo.addItem(name);
                toCombo.addItem(name);
            }
            fromCombo.setSelectedItem("United States"); // set default fromCountry
            toCombo.setSelectedItem("Sri Lanka"); // set default toCountry
        } catch (e) {
            print(e);
        }
        return pane;
    }

    function _handleInvoke(){
        var amount = amountText.getText(); // reads the amount to be converted
        var fromCountry = fromCombo.getSelectedItem(); // reads the country from whcih the amount to be converted
        var toCountry = toCombo.getSelectedItem(); // reads the country to which the amount to be converted

        // Asign an eventlistener for each instance of WSRequest
        req1.onreadystatechange = func1;
        req2.onreadystatechange = func2;
        convReq.onreadystatechange = func3;

        var options = new Array();
        options["useSOAP"] = 1.1;
        options["HTTPMethod"] = "POST";
        options["useWSA"] = "1.0";
        options["action"] = "http://www.webserviceX.NET/GetCurrencyByCountry"

        // Default fromCurrency
        var fromCurrency = "USD";
        // Default toCurrency
        var toCurrency = "LKR";

        try{
            // Open each request asynchronously
            req1.open(options, "http://www.webservicex.net/country.asmx", true);
            req2.open(options, "http://www.webservicex.net/country.asmx", true);

            // Payload for the first request
            var payload = "<GetCurrencyByCountry xmlns=\"http://www.webserviceX.NET\"><CountryName>" +
            fromCountry +
            "</CountryName></GetCurrencyByCountry>";

            print("\nSending Request to get Currency Code for " + fromCountry);
            req1.send(payload);

            // Payload for the second request
            payload = "<GetCurrencyByCountry xmlns=\"http://www.webserviceX.NET\"><CountryName>" +
            toCountry +
            "</CountryName></GetCurrencyByCountry>";

            print("Sending Request to get Currency Code for " + toCountry);
            req2.send(payload);
        } catch (ex){
            print(ex);
        }

        // Wait till both requests complete
        var complete = false;
        while (!complete) {
            java.lang.Thread.sleep(1);
        }


        options = new Array();
        options["useSOAP"] = 1.1;
        options["HTTPMethod"] = "POST";
        options["useWSA"] = "1.0";
        //SOAP action of the ConvesionRate Web Service
        options["action"] = "http://www.webserviceX.NET/ConversionRate"
        //create payload for ConversionRate Web Service
        payload =  "<ConversionRate xmlns=\"http://www.webserviceX.NET/\">" +
                   "<FromCurrency>" + fromCurrency + "</FromCurrency>" +
                   "<ToCurrency>" + toCurrency + "</ToCurrency>" +
                   "</ConversionRate>";

        var convRate;
        try{
            //open convReq with synchronous option
            convReq.open(options, "http://www.webservicex.net/CurrencyConvertor.asmx", false);
            print("\nSending Request to get Conversion Rate from " + fromCurrency + " to " + toCurrency + "\n");
            convReq.send(payload);
        } catch(ex){
            print(ex);
        }

        function func1() {
            if (req1.getReadyState() == 4) {
                var str = req1.responseText;
                //replace &lt; with < in the responseText
                str = str.replaceAll("&lt;", "<");
                //get the currency code out of the responseText
                str = str.split("<CurrencyCode>")[1];
                if(str != null){
                    str = str.substring(0, 3);
                } else {
                    var mesage = "Unsupported Country" + fromCountry + "\nSetting Default Currency Code " + fromCurrency;
                    JOptionPane.showMessageDialog(null, mesage, "Error in Web Service", JOptionPane.ERROR_MESSAGE)
                    str = fromCurrency;
                }
                fromCurrency = str;
                print("\nCurrency Code for " + fromCountry + " -> " + fromCurrency);
                if(req2.getReadyState() == 4){
                    complete = true;
                }
            }
        }

        function func2() {
            if (req2.getReadyState() == 4) {
                var str = req2.responseText;
                //replace &lt; with < in the responseText
                str = str.replaceAll("&lt;", "<");
                //get the currency code out of the responseText
                str = str.split("<CurrencyCode>")[1];
                if(str != null){
                    str = str.substring(0, 3);
                } else {
                    var mesage = "Unsupported Country" + toCountry + "\nSetting Default Currency Code " + toCurrency;
                    JOptionPane.showMessageDialog(null, mesage, "Error in Web Service", JOptionPane.ERROR_MESSAGE)
                    str = toCurrency;
                }
                toCurrency = str;
                print("\nCurrency Code for " + toCountry + " -> " + toCurrency);
                if(req1.readyState == 4){
                    complete = true;
                }
            }
        }

        function func3(){
            if(convReq.readyState == 4){
                convRate = convReq.responseXML.getFirstChild().getFirstChild().getFirstChild().getTextContent();
                print("Rate -> " + convRate)
                var result = new java.lang.String("" + (amount * convRate));
                result += "00";
                result = result.substring(0, (result.indexOf('.') + 3));
                print("Result -> " + result);
                resultText.setText(result);
            }
        }
    }
}

var con = new Converter();
con.init();
