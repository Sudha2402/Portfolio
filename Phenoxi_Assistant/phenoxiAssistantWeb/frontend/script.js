class PhenoxiChat {
    constructor() {
        this.socket = io('http://localhost:5000');
        this.isListening = false;
        this.currentConversation = this.generateSessionId();
        this.conversations = this.loadConversations();
        this.idleTimer = null;
        this.isIdle = true;
        this.animationCooldown = false;
        this.recognition = null;

        // Predefined responses for demo in case of exhaust key
        this.predefinedResponses = {
            // Greetings
            'hello': 'Hello! I\'m Phenoxi, your AI assistant. How can I help you today?',
            'hi': 'Hi there! I\'m Phenoxi. What can I do for you?',
            'hey': 'Hey! Nice to meet you. I\'m here to help!',

            // About Phenoxi
            'who are you': 'I\'m Phenoxi, an AI voice assistant created by Sudha Kumari as a portfolio project. I can help with various tasks and answer your questions!',
            'what is phenoxi': 'Phenoxi is an AI voice assistant built with Python and JavaScript. I can open websites, play music, tell jokes, and have conversations with you!',
            'who made you': 'I was created by Sudha Kumari, a Computer Science Engineering student specializing in AI and full-stack development.',

            // About me Sudha
            'tell me about sudha': 'Sudha Kumari is a BTech Computer Science student at University of Lucknow with 9.1 CGPA. She\'s skilled in DSA, full-stack development, and has built several projects including me!',
            'sudha skills': 'Sudha is proficient in C++, Java, Python, JavaScript, React, Node.js, MongoDB, and has solved 100+ LeetCode problems!',
            'sudha projects': 'Sudha built: Phenoxi Shanaya Bazaar (e-commerce), My Video Book, Code Typing Master, Smart Chatbot, and this Phenoxi Assistant!',
            'sudha education': 'Sudha is pursuing BTech at University of Lucknow (2022-2026) with 9.1 CGPA. She scored 94.8% in 10th and 94.2% in 12th grade.',

            // Actions
            'open google': 'Opening Google for you!',
            'open youtube': 'Launching YouTube!',
            'open linkedin': 'Opening LinkedIn for professional networking!',
            'portfolio': 'Opening Sudha\'s portfolio website!',

            // Music
            'play music': 'I can play music for you! Try saying "play shape" or "play believer"',
            'play shape': 'Playing "Shape of You" by Ed Sheeran!',
            'play believer': 'Playing "Believer" by Imagine Dragons!',
            'play faded': 'Playing "Faded" by Alan Walker!',

            // Fun
            'tell me a joke': 'Why do programmers prefer dark mode? Because light attracts bugs! 😄',
            'fun fact': 'Did you know? The first computer bug was an actual moth found in Harvard\'s Mark II computer in 1947!',

            // Technical
            'what is dsa': 'DSA stands for Data Structures and Algorithms - the foundation of computer science that helps solve complex problems efficiently.',
            'what is mern stack': 'MERN stands for MongoDB, Express.js, React, and Node.js - a popular full-stack JavaScript framework for web development.',
            'what is python': 'Python is a versatile programming language known for its simplicity and wide use in AI, web development, and data science.',

            // Help
            'what can you do': 'I can: Open websites (Google, YouTube, LinkedIn), play music, tell jokes, share information about Sudha, and have conversations!',
            'help': 'Try asking me to: Open websites, play music, tell about Sudha, share a joke, or ask technical questions!'
        };

        this.init();
        this.initSpeechRecognition();

        // Pre-populate with demo conversations if empty
        if (this.conversations.length === 0) {
            this.createDemoConversations();
        }

    }

    init() {
        this.bindEvents();
        this.setupSocketListeners();
        this.createPopularConversationsItem(); // Creating this first message for showing
        this.renderConversationHistory(); // rendering conversations
        this.startIdleDetection();
        this.showWelcomeMessage();
    }

    //POPULAR CONVERSATIONS
    createPopularConversationsItem() {
        const historyList = document.getElementById('historyList');

        // Creating Popular Conversations item
        const popularItem = document.createElement('div');
        popularItem.className = 'history-item popular-conversations';
        popularItem.innerHTML = `
        <i class="fas fa-star"></i>
        <span>Popular Conversations</span>
    `;

        popularItem.addEventListener('click', () => {
            this.loadPopularConversations();
            // Closing sidebar on mobile
            if (window.innerWidth <= 768) {
                document.querySelector('.sidebar').classList.remove('active');
            }
        });

        // Inserting after Current Session
        const currentSession = historyList.querySelector('.history-item.active');
        historyList.insertBefore(popularItem, currentSession.nextSibling);
    }



    //  DISPLAY-ONLY MESSAGES (NO SAVING) in popular conversation so that it remains default and consise to show.
    displayMessageOnly(sender, content) {
        const messagesContainer = document.getElementById('chatMessages');
        const messageDiv = document.createElement('div');
        messageDiv.className = `message ${sender}-message`;

        const avatar = document.createElement('div');
        avatar.className = 'avatar';
        avatar.innerHTML = sender === 'user' ?
            '<i class="fas fa-user"></i>' :
            sender === 'error' ?
                '<i class="fas fa-exclamation-triangle"></i>' :
                '<i class="fas fa-robot"></i>';

        const bubble = document.createElement('div');
        bubble.className = 'bubble';
        bubble.innerHTML = `<p>${content}</p>`;

        messageDiv.appendChild(avatar);
        messageDiv.appendChild(bubble);
        messagesContainer.appendChild(messageDiv);

        // Scroll to bottom
        messagesContainer.scrollTop = messagesContainer.scrollHeight;

        // NOTE: This method does NOT call addToConversation(), so no saving to history
    }



    loadPopularConversations() {
        // Clearing current chat
        this.clearChatInterface();
        this.hideWelcomeMessage();

        // Defining popular conversations
        const popularConversations = [
            {
                question: "Hello",
                answer: "Hello! I'm Phenoxi, your AI assistant. How can I help you today?"
            },
            {
                question: "What can you do?",
                answer: "I can: Open websites (Google, YouTube, LinkedIn), play music, tell jokes, share information about Sudha, and have conversations!"
            },
            {
                question: "Tell me about Sudha",
                answer: "Sudha Kumari is a BTech Computer Science student at University of Lucknow with 9.1 CGPA. She's skilled in DSA, full-stack development, and has built several projects including me!"
            },
            {
                question: "Open Google",
                answer: "Opening Google for you!"
            },
            {
                question: "What is DSA?",
                answer: "DSA stands for Data Structures and Algorithms - the foundation of computer science that helps solve complex problems efficiently."
            },
            {
                question: "Who made you?",
                answer: "I was created by Sudha Kumari, a Computer Science Engineering student specializing in AI and full-stack development."
            },
            {
                question: "Play music",
                answer: "I can play music for you! Try saying 'play shape' or 'play believer'"
            },
            {
                question: "Tell me a joke",
                answer: "Why do programmers prefer dark mode? Because light attracts bugs! 😄"
            },
            {
                question: "Sudha's projects",
                answer: "Sudha built: Phenoxi Shanaya Bazaar (e-commerce), My Video Book, Code Typing Master, Smart Chatbot, and this Phenoxi Assistant!"
            },
            {
                question: "What is MERN stack?",
                answer: "MERN stands for MongoDB, Express.js, React, and Node.js - a popular full-stack JavaScript framework for web development."
            }
        ];



        // Adding each conversation to chat using displayMessageOnly (NO SAVING)
        popularConversations.forEach((conv, index) => {
            setTimeout(() => {
                this.displayMessageOnly('user', `Q: ${conv.question}`);
                this.displayMessageOnly('assistant', `A: ${conv.answer}`);
            }, index * 300);
        });

        // Updating current conversation title but don't saving to history
        this.updateCurrentConversationTitle("Popular Conversations Demo");
    }

    // Also updating the updateCurrentConversationTitle method to prevent saving Popular Conversations:
    updateCurrentConversationTitle(title) {
        // Only updating title for actual conversations, not Popular Conversations demo
        if (title !== "Popular Conversations Demo") {
            let conversation = this.conversations.find(c => c.id === this.currentConversation);
            if (conversation) {
                conversation.title = title;
                this.saveConversations();
                this.renderConversationHistory();
            }
        }
    }


    // DEMO CONVERSATIONS
    createDemoConversations() {
        const demoConversations = [
            {
                question: "What can you do?",
                answer: this.predefinedResponses['what can you do']
            },
            {
                question: "Tell me about Sudha",
                answer: this.predefinedResponses['tell me about sudha']
            },
            {
                question: "Open Google",
                answer: this.predefinedResponses['open google']
            },
            {
                question: "What is DSA?",
                answer: this.predefinedResponses['what is dsa']
            },
            {
                question: "Who made you?",
                answer: this.predefinedResponses['who made you']
            },
            {
                question: "Play music",
                answer: this.predefinedResponses['play music']
            }
        ];

        demoConversations.forEach((demo, index) => {
            const conversationId = 'demo_' + index;
            const conversation = {
                id: conversationId,
                title: demo.question.substring(0, 30) + (demo.question.length > 30 ? '...' : ''),
                messages: [
                    { sender: 'user', content: demo.question, timestamp: Date.now() - (demoConversations.length - index) * 60000 },
                    { sender: 'assistant', content: demo.answer, timestamp: Date.now() - (demoConversations.length - index) * 59000 }
                ],
                timestamp: Date.now() - (demoConversations.length - index) * 60000
            };
            this.conversations.push(conversation);
        });

        this.saveConversations();
        this.renderConversationHistory();
    }

    // RESPONSE PROCESSING
    processCommand(command) {
        const lowerCommand = command.toLowerCase().trim();

        // Check predefined responses first
        let response = this.getPredefinedResponse(lowerCommand);

        if (response) {
            return response;
        }

        // If no predefined response, try AI (via backend)
        return null; // Will be handled by backend
    }

    getPredefinedResponse(command) {
        // Exact match
        if (this.predefinedResponses[command]) {
            return this.predefinedResponses[command];
        }

        // Partial match
        for (const [key, value] of Object.entries(this.predefinedResponses)) {
            if (command.includes(key)) {
                return value;
            }
        }

        return null;
    }

    handleActions(command, response) {
        const lowerCommand = command.toLowerCase();

        if (lowerCommand.includes('open google') || response.includes('Opening Google')) {
            setTimeout(() => window.open('https://google.com', '_blank'), 500);
        }
        else if (lowerCommand.includes('open youtube') || response.includes('Launching YouTube')) {
            setTimeout(() => window.open('https://youtube.com', '_blank'), 500);
        }
        else if (lowerCommand.includes('open linkedin') || response.includes('Opening LinkedIn')) {
            setTimeout(() => window.open('https://linkedin.com', '_blank'), 500);
        }
        else if (lowerCommand.includes('portfolio') || response.includes('portfolio')) {
            setTimeout(() => window.open('http://sudha-kumari-portfolio.infinityfreeapp.com/', '_blank'), 500);
        }
    }

    //  BACKEND COMMUNICATION 
    setupSocketListeners() {
        this.socket.on('connect', () => {
            console.log('Connected to server');
            this.updateStatus('Connected', 'connected');
        });

        this.socket.on('disconnect', () => {
            console.log('Disconnected from server');
            this.updateStatus('Disconnected', 'disconnected');
        });

        this.socket.on('assistant_response', (data) => {
            console.log('Received response:', data);
            this.hideLoading();

            if (data.type === 'error') {
                this.addMessage('error', data.content);
            } else {
                this.addMessage('assistant', data.content);
                this.speakResponse(data.content);
                this.handleActions(data.originalCommand || '', data.content);
            }
        });
    }

    sendToBackend(command) {
        this.showLoading();

        // Send via WebSocket to backend
        this.socket.emit('text_command', {
            command: command,
            session: this.currentConversation
        });
    }

    // ==================== SPEECH RECOGNITION ====================
    initSpeechRecognition() {
        if ('webkitSpeechRecognition' in window || 'SpeechRecognition' in window) {
            const SpeechRecognition = window.SpeechRecognition || window.webkitSpeechRecognition;
            this.recognition = new SpeechRecognition();
            this.recognition.continuous = false;
            this.recognition.interimResults = false;
            this.recognition.lang = 'en-US';

            this.recognition.onstart = () => {
                this.updateVoiceVisualizer(true);
                this.updateStatus('🎤 Listening... Speak now', 'active');
            };

            this.recognition.onresult = (event) => {
                const transcript = event.results[0][0].transcript;
                this.addMessage('user', transcript);
                this.hideWelcomeMessage();
                this.sendToBackend(transcript);
            };

            this.recognition.onerror = (event) => {
                if (event.error !== 'no-speech') {
                    console.error('Speech recognition error:', event.error);
                }
                this.stopVoiceListening();
                this.updateStatus('Ready to help', 'ready');
            };

            this.recognition.onend = () => {
                this.updateVoiceVisualizer(false);
                if (this.isListening) {
                    setTimeout(() => {
                        if (this.isListening) this.recognition.start();
                    }, 100);
                }
            };
        }
    }

    toggleVoiceListening() {
        this.resetIdleTimer();

        if (!this.isListening) {
            this.startVoiceListening();
        } else {
            this.stopVoiceListening();
        }
    }

    startVoiceListening() {
        if (!this.recognition) {
            this.addMessage('error', 'Speech recognition not available');
            return;
        }

        try {
            this.isListening = true;
            this.recognition.start();

            const voiceBtn = document.getElementById('voiceButton');
            voiceBtn.classList.add('listening');
            voiceBtn.querySelector('i').className = 'fas fa-microphone-slash';
            voiceBtn.querySelector('span').textContent = 'Stop Listening';

            this.hideWelcomeMessage();

        } catch (error) {
            console.error('Error starting speech recognition:', error);
            this.addMessage('error', 'Error starting microphone. Please check permissions.');
            this.stopVoiceListening();
        }
    }

    stopVoiceListening() {
        this.isListening = false;

        if (this.recognition) {
            try {
                this.recognition.stop();
            } catch (error) {
                console.error('Error stopping recognition:', error);
            }
        }

        const voiceBtn = document.getElementById('voiceButton');
        voiceBtn.classList.remove('listening');
        voiceBtn.querySelector('i').className = 'fas fa-microphone';
        voiceBtn.querySelector('span').textContent = 'Click to Talk';

        this.updateVoiceVisualizer(false);
        this.updateStatus('Ready to help', 'ready');
    }

    // ==================== TEXT-TO-SPEECH ====================
    speakResponse(text) {
        if ('speechSynthesis' in window) {
            window.speechSynthesis.cancel();

            const utterance = new SpeechSynthesisUtterance(text);
            utterance.rate = 0.8;
            utterance.pitch = 1;
            utterance.volume = 0.8;

            utterance.onstart = () => {
                console.log('Started speaking');
            };

            utterance.onend = () => {
                console.log('Finished speaking');
            };

            utterance.onerror = (event) => {
                console.error('Speech synthesis error:', event);
            };

            window.speechSynthesis.speak(utterance);
        }
    }

    // ==================== UI METHODS ====================
    bindEvents() {
        // Sidebar toggle
        document.getElementById('sidebarToggle').addEventListener('click', () => {
            document.querySelector('.sidebar').classList.toggle('active');
            this.resetIdleTimer();
        });

        // New chat button
        document.getElementById('newChatBtn').addEventListener('click', () => {
            this.startNewConversation();
            this.resetIdleTimer();
        });

        // Clear chat button
        document.getElementById('clearChatBtn').addEventListener('click', () => {
            this.clearCurrentChat();
            this.resetIdleTimer();
        });

        // Text input
        document.getElementById('sendButton').addEventListener('click', () => this.sendTextMessage());
        document.getElementById('textInput').addEventListener('keypress', (e) => {
            if (e.key === 'Enter') this.sendTextMessage();
        });

        // Voice control
        document.getElementById('voiceButton').addEventListener('click', () => this.toggleVoiceListening());

        // Quick actions and suggestions
        document.querySelectorAll('.quick-btn, .suggestion-btn').forEach(btn => {
            btn.addEventListener('click', (e) => {
                e.stopPropagation();
                const command = btn.getAttribute('data-command');
                this.sendQuickCommand(command);
            });
        });

        // Idle indicator click
        const idleIndicator = document.getElementById('idleIndicator');
        if (idleIndicator) {
            idleIndicator.addEventListener('click', () => {
                this.resetIdleTimer();
                document.getElementById('textInput').focus();
            });
        }

        // Close sidebar when clicking on chat area (mobile)
        document.querySelector('.chat-area').addEventListener('click', () => {
            if (window.innerWidth <= 768) {
                document.querySelector('.sidebar').classList.remove('active');
            }
        });
    }

    sendTextMessage() {
        this.resetIdleTimer();
        const input = document.getElementById('textInput');
        const message = input.value.trim();

        if (message) {
            this.addMessage('user', message);
            input.value = '';
            this.hideWelcomeMessage();
            this.sendToBackend(message);
        }
    }

    sendQuickCommand(command) {
        this.resetIdleTimer();
        this.addMessage('user', command);
        this.hideWelcomeMessage();
        this.sendToBackend(command);
    }

    // ==================== CONVERSATION MANAGEMENT ====================
    generateSessionId() {
        return 'session_' + Date.now();
    }

    loadConversations() {
        const saved = localStorage.getItem('phenoxi_conversations');
        return saved ? JSON.parse(saved) : [];
    }

    saveConversations() {
        localStorage.setItem('phenoxi_conversations', JSON.stringify(this.conversations));
    }

    startNewConversation() {
        this.currentConversation = this.generateSessionId();
        this.clearChatInterface();
        this.renderConversationHistory();
        this.showWelcomeMessage();
    }

    clearCurrentChat() {
        if (confirm('Are you sure you want to clear this conversation?')) {
            this.clearChatInterface();
            this.showWelcomeMessage();
        }
    }

    clearChatInterface() {
        document.getElementById('chatMessages').innerHTML = '';
        document.getElementById('textInput').value = '';
    }

    showWelcomeMessage() {
        document.getElementById('welcomeMessage').style.display = 'flex';
        document.getElementById('chatMessages').style.display = 'none';
    }

    hideWelcomeMessage() {
        document.getElementById('welcomeMessage').style.display = 'none';
        document.getElementById('chatMessages').style.display = 'flex';
    }

    addMessage(sender, content) {
        const messagesContainer = document.getElementById('chatMessages');
        const messageDiv = document.createElement('div');
        messageDiv.className = `message ${sender}-message`;

        const avatar = document.createElement('div');
        avatar.className = 'avatar';
        avatar.innerHTML = sender === 'user' ?
            '<i class="fas fa-user"></i>' :
            sender === 'error' ?
                '<i class="fas fa-exclamation-triangle"></i>' :
                '<i class="fas fa-robot"></i>';

        const bubble = document.createElement('div');
        bubble.className = 'bubble';
        bubble.innerHTML = `<p>${content}</p>`;

        messageDiv.appendChild(avatar);
        messageDiv.appendChild(bubble);
        messagesContainer.appendChild(messageDiv);

        // Scroll to bottom
        messagesContainer.scrollTop = messagesContainer.scrollHeight;

        // Add to current conversation (except for system/error messages)
        if (sender === 'user' || sender === 'assistant') {
            this.addToConversation(sender, content);
        }
    }

    addToConversation(sender, content) {
        let conversation = this.conversations.find(c => c.id === this.currentConversation);

        if (!conversation) {
            conversation = {
                id: this.currentConversation,
                title: content.substring(0, 30) + (content.length > 30 ? '...' : ''),
                messages: [],
                timestamp: Date.now()
            };
            this.conversations.unshift(conversation);
        }

        conversation.messages.push({ sender, content, timestamp: Date.now() });
        conversation.timestamp = Date.now();
        conversation.title = content.substring(0, 30) + (content.length > 30 ? '...' : '');

        this.saveConversations();
        this.renderConversationHistory();
    }


    // ==================== CONVERSATION HISTORY RENDERING ====================
    renderConversationHistory() {
        const historyList = document.getElementById('historyList');

        // Store the current static items (Current Session and Popular Conversations)
        const currentSession = historyList.querySelector('.history-item.active');
        const popularConversations = historyList.querySelector('.popular-conversations');

        // Clear the list
        historyList.innerHTML = '';

        // Re-add Current Session first
        if (currentSession) {
            historyList.appendChild(currentSession);
        } else {
            // Create Current Session if it doesn't exist
            const currentItem = document.createElement('div');
            currentItem.className = 'history-item active';
            currentItem.innerHTML = `
            <i class="fas fa-comment"></i>
            <span>Current Session</span>
            <i class="fas fa-trash delete-btn"></i>
        `;
            currentItem.querySelector('.delete-btn').addEventListener('click', (e) => {
                e.stopPropagation();
                this.clearCurrentChat();
            });
            historyList.appendChild(currentItem);
        }

        // Re-add Popular Conversations
        if (popularConversations) {
            historyList.appendChild(popularConversations);
        } else {
            // Create Popular Conversations if it doesn't exist
            this.createPopularConversationsItem();
        }

        // Add previous conversations (limit to 10)
        this.conversations
            .filter(conv => conv.id !== this.currentConversation)
            .slice(0, 10)
            .forEach(conv => {
                const item = document.createElement('div');
                item.className = 'history-item';
                item.innerHTML = `
                <i class="fas fa-comment"></i>
                <span>${conv.title}</span>
                <i class="fas fa-trash delete-btn"></i>
            `;

                item.addEventListener('click', () => this.loadConversation(conv.id));
                item.querySelector('.delete-btn').addEventListener('click', (e) => {
                    e.stopPropagation();
                    this.deleteConversation(conv.id);
                });

                historyList.appendChild(item);
            });
    }

    rebindStaticItemEvents() {
        // Re-bind Current Session events
        const currentSession = document.querySelector('.history-item.active');
        if (currentSession) {
            const deleteBtn = currentSession.querySelector('.delete-btn');
            if (deleteBtn) {
                deleteBtn.addEventListener('click', (e) => {
                    e.stopPropagation();
                    this.clearCurrentChat();
                });
            }
        }

        // Re-bind Popular Conversations events
        const popularItem = document.querySelector('.popular-conversations');
        if (popularItem) {
            popularItem.addEventListener('click', () => {
                this.loadPopularConversations();
                // Close sidebar on mobile
                if (window.innerWidth <= 768) {
                    document.querySelector('.sidebar').classList.remove('active');
                }
            });
        }
    }

    loadConversation(conversationId) {
        const conversation = this.conversations.find(c => c.id === conversationId);
        if (conversation) {
            this.currentConversation = conversationId;
            this.clearChatInterface();
            this.hideWelcomeMessage();

            // Only update the chat area, don't re-render sidebar
            conversation.messages.forEach(msg => {
                this.addMessage(msg.sender, msg.content);
            });

            // Update active state in sidebar without full re-render
            this.updateSidebarActiveState();
        }
    }

    updateSidebarActiveState() {
        // Remove active class from all items
        document.querySelectorAll('.history-item').forEach(item => {
            item.classList.remove('active');
        });

        // Add active class to current session
        const currentSession = document.querySelector('.history-item.active');
        if (currentSession) {
            currentSession.classList.add('active');
        }
    }

    startNewConversation() {
        this.currentConversation = this.generateSessionId();
        this.clearChatInterface();
        this.updateSidebarActiveState(); // Only update active state
        this.showWelcomeMessage();
    }

    deleteConversation(conversationId) {
        if (confirm('Delete this conversation?')) {
            this.conversations = this.conversations.filter(c => c.id !== conversationId);
            this.saveConversations();

            // Only re-render the conversation list part, keep static items
            this.renderConversationHistory();

            if (conversationId === this.currentConversation) {
                this.startNewConversation();
            }
        }
    }

    // ==================== STATUS AND VISUAL UPDATES ====================
    updateStatus(message, status) {
        const statusText = document.getElementById('statusText');
        const statusDot = document.getElementById('statusDot');

        if (statusText && statusDot) {
            statusText.textContent = message;

            const colors = {
                'connected': '#4ade80',
                'disconnected': '#ef4444',
                'active': '#3b82f6',
                'processing': '#f59e0b',
                'ready': '#4ade80'
            };

            statusDot.style.background = colors[status] || '#6b7280';
        }
    }

    updateVoiceVisualizer(active) {
        const visualizer = document.getElementById('visualizer');
        if (visualizer) {
            if (active) {
                visualizer.classList.add('active');
            } else {
                visualizer.classList.remove('active');
            }
        }
    }

    showLoading() {
        const loading = document.getElementById('loading');
        if (loading) {
            loading.style.display = 'flex';
        }
    }

    hideLoading() {
        const loading = document.getElementById('loading');
        if (loading) {
            loading.style.display = 'none';
        }
    }

    // ==================== IDLE DETECTION ====================
    startIdleDetection() {
        this.resetIdleTimer();

        const activityEvents = ['mousedown', 'mousemove', 'keypress', 'scroll', 'touchstart', 'click'];
        activityEvents.forEach(event => {
            document.addEventListener(event, () => this.resetIdleTimer(), true);
        });

        document.getElementById('textInput').addEventListener('input', () => this.resetIdleTimer());
        document.getElementById('textInput').addEventListener('focus', () => this.resetIdleTimer());
    }

    resetIdleTimer() {
        this.isIdle = false;
        this.hideIdleIndicator();

        if (this.idleTimer) {
            clearTimeout(this.idleTimer);
        }

        this.idleTimer = setTimeout(() => {
            this.handleIdleState();
        }, 30000);
    }

    handleIdleState() {
        this.isIdle = true;
        this.showIdleIndicator();

        if (!this.animationCooldown && this.shouldShowIdleAnimation()) {
            setTimeout(() => {
                if (this.isIdle) {
                    this.showIdleAnimation();
                }
            }, 2000);
        }

        this.idleTimer = setTimeout(() => {
            if (this.isIdle) {
                this.handleIdleState();
            }
        }, 30000);
    }

    shouldShowIdleAnimation() {
        const chatMessages = document.getElementById('chatMessages');
        const hasConversation = chatMessages.children.length > 0;
        const welcomeVisible = document.getElementById('welcomeMessage').style.display === 'flex';

        return hasConversation || !welcomeVisible;
    }

    showIdleAnimation() {
        const animation = document.getElementById('chatbotAnimation');
        const iframe = document.getElementById('lottieIframe');

        if (!animation || !iframe) return;

        iframe.src = iframe.src;
        animation.classList.add('playing');

        setTimeout(() => {
            animation.classList.remove('playing');
        }, 8000);
    }

    showIdleIndicator() {
        const indicator = document.getElementById('idleIndicator');
        if (indicator) {
            indicator.classList.add('visible');
        }
    }

    hideIdleIndicator() {
        const indicator = document.getElementById('idleIndicator');
        if (indicator) {
            indicator.classList.remove('visible');
        }
    }
}

// Initialize the chat when page loads
let phenoxiChat;
document.addEventListener('DOMContentLoaded', () => {
    phenoxiChat = new PhenoxiChat();
});