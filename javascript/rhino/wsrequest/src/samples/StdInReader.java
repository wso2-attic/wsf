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

package samples;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;


public class StdInReader {
    /**
     * Reads an input from the keyboard and returns it as an string
     * @return A string representing the keyboard input
     * @throws IOException
     */
    public static String readLine() throws IOException {
        BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in));
        return stdIn.readLine();
    }
}
