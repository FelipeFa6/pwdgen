function generatePassword() {
    const includeSymbols = document.getElementById('includeSymbols').checked;
    const includeNumbers = document.getElementById('includeNumbers').checked;
    const includeLetters = document.getElementById('includeLetters').checked;
    const passwordLength = document.getElementById('passwordLength').value;

    const symbols = "!@#$%^&*()_+[]{}|;:,.<>?";
    const numbers = "0123456789";
    const letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    let validChars = "";
    if (includeSymbols) validChars += symbols;
    if (includeNumbers) validChars += numbers;
    if (includeLetters) validChars += letters;

    let password = "";
    for (let i = 0; i < passwordLength; i++) {
        const randomIndex = Math.floor(Math.random() * validChars.length);
        password += validChars.charAt(randomIndex);
    }

    document.getElementById('generatedPassword').value = password;
}

document.getElementById('passwordLength').addEventListener('input', function() {
    document.getElementById('passwordLengthDisplay').innerText = this.value;
});

