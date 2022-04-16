**Protocol SCP**

| Number | Result |
| :----: | :--------------- |
| 1xx    | Information      |
| 2xx    | Success          |
| 3xx    | Demi-Success     |
| 4xx    | Demi-Failure     |
| 5xx    | Failure          |
| x0x    | Information      |
| x1x    | Syntaxe          |
| x2x    | Connexion        |
| x3x    | Authentification |
| x4x    | Message system   |
| x5x    | Listing          |

| Code | Signification |
| :--: | :------------------ |
| 101  | Help information    |
| 130  | User login          |
| 140  | Message received    |
| 151  | Team created        |
| 152  | Channel created     |
| 153  | Thread created      |
| 154  | Reply created       |
| 200  | List all users      |
| 201  | List one user       |
| 202  | Success team create |
| 203  | Success channel create |
| 204  | Success thread create |
| 205  | Success reply create|
| 208  | List all team       |
| 209  | List all subscribed |
| 220  | Connexion sucess    |
| 221  | Deconnection sucess |
| 222  | Subscribe success   |
| 223  | Unsubscribe success |
| 230  | Login success       |
| 231  | Logout success      |
| 241  | List all messages   |
| 251  | list cmd (/use)     |
| 252  | list cmd (/use "team_uuid") |
| 253  | list cmd (/use "team_uuid" "channel_uuid") |
| 254  | list cmd (/use "team_uuid" "channel_uuid" "thread_uuid) |
| 255  | Info cmd (/use "team_uuid" "channel_uuid") |
| 256  | Info cmd (/use "team_uuid") |
| 257  | Info cmd (/use "team_uuid" "channel_uuid") |
| 258  | Info cmd (/use "team_uuid" "channel_uuid" "thred_uuid") |
| 400  | Unknown user        |
| 401  | Unknown team        |
| 402  | Unknown channel     |
| 403  | Unknown thread      |
| 500  | Command not found   |
| 501  | Already exists      |
| 515  | Bad arguments + usage |
