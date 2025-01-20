/*
    Programador..........: (c) Tiago Machado 
    Data.................: 20/01/2025 
    Observações..........: Led + Botão
*/
  
    // Constantes
    const byte PINO_LED = 12;
    const byte PINO_BOTAO = 3;

    // Variáveis de estado
    int estadoBotao = LOW; // Estado atual do botão
    int ultimoEstadoBotao = LOW; // Último estado lido do botão
  
    unsigned long tempoUltimoDebounce = 0; // Última alteração de estado
    const unsigned long tempoDebounce = 50; // Tempo de debounce (ms)

    // Inicialização
    void setup(void) {
      pinMode(PINO_LED, OUTPUT);
      pinMode(PINO_BOTAO, INPUT_PULLUP); // Ativa resistor interno de pull-up
}

    // Programa principal
    void loop(void) {
      lerEstadoBotao(); // Atualiza o estado do botão

    // Controla o LED com base no estado do botão
    if (estadoBotao == HIGH) {
      digitalWrite(PINO_LED, HIGH); // Liga o LED
  
  } else {
      digitalWrite(PINO_LED, LOW); // Desliga o LED
    
    }
}

    // Função para ler o estado do botão com debounce
    void lerEstadoBotao() {
      int leitura = digitalRead(PINO_BOTAO); // Lê o estado do botão

      // Detecta alteração no estado do botão
      if (leitura != ultimoEstadoBotao) {
        tempoUltimoDebounce = millis(); // Atualiza o tempo de debounce
}

      // Verifica se o tempo de debounce já passou
      if ((millis() - tempoUltimoDebounce) > tempoDebounce) {
      
      // Atualiza o estado do botão se houve alteração confirmada
      if (leitura != estadoBotao) {
        estadoBotao = leitura;
    }
  }

    // Atualiza o último estado lido
    ultimoEstadoBotao = leitura;
}
