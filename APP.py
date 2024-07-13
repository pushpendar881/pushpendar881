
import streamlit as st
import pickle

# Initialize session state for 'page' if not already set
if 'page' not in st.session_state:
    st.session_state.page = 'Home'

st.title('AI Content Authenticity')

def remove_tags(text):
    tags = ['\n', '\'']
    for tag in tags:
        text = text.replace(tag, '')
    return text

pipeline = pickle.load(open('pipeline.pkl', 'rb'))

def home_page():
    st.markdown('This app is used to detect the authenticity of the content.')
    st.markdown('Please enter the content in the text box  in prediction section and click on the submit button to see the result.')
    st.markdown('The result will be displayed in the text box below.')
    st.markdown('---')

def prediction():
    text = st.text_input("Enter your text: ")
    text_removetag = remove_tags(text)
    if st.button('Submit'):
        result = pipeline.predict([text_removetag])
        if result == 0:
            st.markdown("---")
            st.text("Input: ")
            st.text("The Given  text  is : {}".format(text))
            st.text("Output: ")
            st.text("The text is Human written.")
            st.markdown("---")
            st.success("Output generated successfully")
        else:
            st.markdown("---")
            st.text("Input: ")
            st.text("The Given  text  is : {}".format(text))
            st.text("Output: ")
            st.text("The text is Machine written.")
            st.markdown("---")
            st.success("Output generated successfully")

def about_us_page():
    st.markdown("<h1>ALPHA CODERS</h1>", unsafe_allow_html=True)
    st.markdown('This app is developed by a team of 2 students of VESIT.')
    st.markdown('---')
    st.markdown("<h3>TEAM MEMBERS:</h3>", unsafe_allow_html=True)
    st.text("1. Pushpendar Choudhary")
    st.text("2. Nishant Gosavi")
    st.markdown('---')

# Sidebar navigation
st.sidebar.title("ALPHA CODERS")
if st.sidebar.button("Home"):
    st.session_state.page = 'Home'
if st.sidebar.button("Prediction"):
    st.session_state.page = 'Prediction'
if st.sidebar.button("About Us"):
    st.session_state.page = 'About Us'

# Page routing
if st.session_state.page == 'Home':
    home_page()
elif st.session_state.page == 'Prediction':
    prediction()
elif st.session_state.page == 'About Us':
    about_us_page()
