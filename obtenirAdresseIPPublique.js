const request = require('request');

function obtenirAdresseIPPublique() {
    request('https://api.ipify.org?format=json', (error, response, body) => {
        if (!error && response.statusCode == 200) {
            const adresseIPPublique = JSON.parse(body).ip;
            console.log("Adresse IP Publique: " + adresseIPPublique);
        } else {
            console.log("Erreur : " + response.statusCode);
        }
    });
}

obtenirAdresseIPPublique();
